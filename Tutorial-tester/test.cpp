
#include <iostream>
#include <vector>
#include <random>
#include <list>
#include <string>

#include <functional>
#include <random>
#include <algorithm>

#include <fstream>


double multiply(double a, double b) {
    return a * b;
}


template <typename T>
T square(T x){
    return x * x ;

}
class vehicle {
    private:
        int wheels;
        std::string color;
    public:
        vehicle(int w = 4, std::string c = "red") : wheels(w), color(c) {}
        virtual void display() {
            std::cout << "Vehicle with " << wheels << " wheels and color " << color << std::endl;
        }

        virtual ~vehicle() {}
};


class car : public vehicle {
    private:
        std::string model;
    public: 
        car(int w = 4, std::string c = "red", std::string m = "sedan") : vehicle(w, c), model(m) {}
        void display() override {
            vehicle::display();
            std::cout << "Car model: " << model << std::endl;   
        }
};


class Animal {
    public:
    void walk() {
        std::cout << "animal walked" << std::endl;
    }
};


class Dog : public Animal {
    public:
    std::string legs = "4";

};

class CatVroom : public Animal, public vehicle {
    public:
    std::string legs = "4";

};

int add(int a, int b) {
    return a + b;
}
double add(double a, double b) {
    return a + b;
}

class Point {
    public:
        int x, y;
        Point(int x, int y) : x(x), y(y) {}
        Point operator+(const Point& other) {
            return Point(x + other.x, y + other.y);
        }

};


int main() {
    for (int i = 0; i < 4; ++i) {
        std::cout << i << " ";
        
    }

    std::cout << std::endl;
    std::vector<int> v;
    v.push_back(99);

    for(int i : v) {
        std::cout << i << " ";
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10);
    
    int n = dist(gen);

    std::cout << "\nRandom number: " << n << std::endl;
    std::cout << "Multiplication result: " << multiply(3.2, 4.2) << std::endl;

    std::cout << "Square result: " << square(-1.0) << std::endl;


    std::cout <<"** VECTOR ** container guarantees O(1) amortized push_back and random access" << std::endl;


    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    for (auto it = lst.begin(); it != lst.end(); ++it){
        std::cout << *it << " ";
    }

    vehicle *v1 = new vehicle(4, "blue");
    vehicle *v2 = new car(4, "red", "SUV");
    v1->display();
    v2->display();


    std::cout << add(1, 2) << "\n";
    std::cout << add(1.5, 2.322121) << "\n";



    Dog d;

    d.walk();
    
    std::cout << "Dog has " << d.legs << " legs" << std::endl;

    CatVroom c;
    c.walk();
    c.display();



    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2; 
    std::cout << "Point p3: (" << p3.x << ", " << p3.y << ")" << std::endl;


    int factor = 2;
    auto multiplyby2 = [factor](int x) { return x * factor; };

    int result = multiplyby2(5); // result will be 10
    std::cout << "Lambda result: " << result << std::endl;


    auto squareLambda = [](int x) { return x * x; };

    int squareResult = squareLambda(5); // result will be 25
    std::cout << "Lambda square result: " << squareResult << std::endl;



    std::function<int(int)> multiplyBy3 = [] (int x) { return x * 3; };
    int result2 = multiplyBy3(5); // result will be 15
    std::cout << "std::function result: " << result2 << std::endl;

    std::random_device rnd;
    std::mt19937 gen2(rnd());
    std::uniform_int_distribution<int> dist2(1,100);

    int randomNum = dist2(gen);
    std::cout << "Random number: " << randomNum << std::endl;

    std::vector<int> numbers = {13, 2, 3, 5, 56};
    square(numbers.at(3));
    std::cout << "Square of fourth element: " << numbers[0] << std::endl;

    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }

    std::list<int> myList = {1, 2, 3, 4, 5};

    std::cout << "\nList elements, it loop: ";

    for (auto it = myList.begin(); it != myList.end(); ++it){
        std::cout << *it << " ";
    }


    std::ifstream fin("data.txt");

    std::string line;
    
    while (std::getline(fin,line)){
        std::cout << line << std::endl;
    }
    

    return 0;
}
     
