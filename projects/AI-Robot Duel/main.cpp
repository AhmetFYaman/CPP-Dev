#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <random>
#include <thread>
#include <chrono>


class AttackStrategy {
public:
    virtual ~AttackStrategy() = default;
    virtual int execute() const = 0;
};

// drill attack for guaranteed 15 damage
class DrillAttack : public AttackStrategy {
public:
    int execute() const override {
        return 15; 
    }
};

// laser attack for a risky damage between 5 and 25
class LaserAttack : public AttackStrategy {
public:
    int execute() const override {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(5, 25);
        return distrib(gen); 
    }
};


class Robot {
private:
    std::string name;
    int hitPoints;
    

    std::unique_ptr<AttackStrategy> strategy;
    
 
    std::function<int()> attackFunction;
    

    bool usingStrategy;

public:

    Robot(const std::string& robotName, AttackStrategy* attackStrategy)
        : name(robotName), hitPoints(100), strategy(attackStrategy), usingStrategy(true) {}
    

    Robot(const std::string& robotName, std::function<int()> attackFunc)
        : name(robotName), hitPoints(100), attackFunction(attackFunc), usingStrategy(false) {}
    

    int attack() const {
        if (usingStrategy) {
            return strategy->execute();
        } else {
            return attackFunction();
        }
    }
    

    void takeDamage(int damage) {
        hitPoints -= damage;
        if (hitPoints < 0) {
            hitPoints = 0;
        }
    }
    

    const std::string& getName() const { return name; }
    int getHitPoints() const { return hitPoints; }
    bool isAlive() const { return hitPoints > 0; }
};


void simulateRound(Robot& robot1, Robot& robot2) {

    int robot1Hit = robot1.attack();
    int robot2Hit = robot2.attack();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::cout << robot1.getName() << " attacks for " << robot1Hit << " damage!" << std::endl;
    std::cout << robot2.getName() << " attacks for " << robot2Hit << " damage!" << std::endl;
    

    robot2.takeDamage(robot1Hit);
    robot1.takeDamage(robot2Hit);
    

    std::cout << robot1.getName() << "'s HP: " << robot1.getHitPoints() << std::endl;
    std::cout << robot2.getName() << "'s HP: " << robot2.getHitPoints() << std::endl;
    
 
    if (robot1Hit > robot2Hit) {
        std::cout << robot1.getName() << " wins this round!" << std::endl;
    } else if (robot2Hit > robot1Hit) {
        std::cout << robot2.getName() << " wins this round!" << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }
    
    std::cout << "------------------------------" << std::endl;
}


void displayTitle() { 
    std::cout << "\n"
              << " ██████╗  ██████╗ ██████╗  ██████╗ ████████╗    ██████╗ ██╗   ██╗███████╗██╗     \n"
              << " ██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗╚══██╔══╝    ██╔══██╗██║   ██║██╔════╝██║     \n"
              << " ██████╔╝██║   ██║██████╔╝██║   ██║   ██║       ██║  ██║██║   ██║█████╗  ██║     \n"
              << " ██╔══██╗██║   ██║██╔══██╗██║   ██║   ██║       ██║  ██║██║   ██║██╔══╝  ██║     \n"
              << " ██║  ██║╚██████╔╝██████╔╝╚██████╔╝   ██║       ██████╔╝╚██████╔╝███████╗███████╗\n"
              << " ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝    ╚═╝       ╚═════╝  ╚═════╝ ╚══════╝╚══════╝\n"
              << "                                                                                  \n";
}

int main() {
    displayTitle();  // it works in codebin trust, play in codebin mister tester
    

    
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "Welcome to the ultimate robot battle simulator!" << std::endl;
    std::cout << "Two robots, Timmy and John will duel until only one is left standing." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::cout << "Let the battle Begin!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    Robot* Timmy = nullptr;
    Robot* John = nullptr;
    



    Timmy = new Robot("Timmy", new DrillAttack());
    John = new Robot("John", new LaserAttack());

    
    std::cout << "\nBeginning duel between " << Timmy->getName() << " and " << John->getName() << "!" << std::endl;
    std::cout << "Both robots start with 100 hit points." << std::endl;
    std::cout << "------------------------------" << std::endl;
    
    int round = 1;
    

    while (Timmy->isAlive() && John->isAlive()) {
        std::cout << "Round " << round << ":" << std::endl;
        simulateRound(*Timmy, *John);
        round++;
        

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    

    std::cout << "\n=== DUEL RESULT ===" << std::endl;
    if (!Timmy->isAlive() && !John->isAlive()) {
        std::cout << "Both robots have been destroyed! It's a draw!" << std::endl;
    } else if (!Timmy->isAlive()) {
        std::cout << John->getName() << " is victorious with " << John->getHitPoints() << " HP remaining!" << std::endl;
    } else {
        std::cout << Timmy->getName() << " is victorious with " << Timmy->getHitPoints() << " HP remaining!" << std::endl;
    }
    
// Clean up the battle field because we dont leave memory leaks behind, you thought I would forget
    delete Timmy;
    delete John;
    
    return 0;
}