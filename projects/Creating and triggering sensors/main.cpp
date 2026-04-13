#include <iostream>
#include <vector>
#include <memory>


class Sensor {
public:
    virtual void trigger() const = 0;
    virtual ~Sensor() = default;
};


class MotionSensor : public Sensor {
public:
    void trigger() const override {
        std::cout << "Warnning! Motion detected in the Museum" << std::endl;
    }
};


class GlassBreakSensor : public Sensor {
public:
    void trigger() const override {
        std::cout << "Warning! Glass breaking detected in the Museum" << std::endl;
    }
};


class ThermalSensor : public Sensor { 
public:
    void trigger() const override {
        std::cout << "Warning! Museum getting too warm/too cold" << std::endl;
    }
};

int main() {
    
    std::vector<std::unique_ptr<Sensor>> sensors;
    
    
    sensors.push_back(std::make_unique<MotionSensor>());
    sensors.push_back(std::make_unique<GlassBreakSensor>());
    sensors.push_back(std::make_unique<ThermalSensor>());
    
    
    std::cout << "Museum Security System Test\n";
    std::cout << "==========================\n";
    for (const auto& sensor : sensors) {
        sensor->trigger();
    }
    
    return 0;
}