#include "electric_motor.h"

namespace car::component {

    ElectricMotor::ElectricMotor()
        : Engine(400, 200), battery_capacity_(75.0) {
    }

    void ElectricMotor::Start() {
        if (!is_on_) {
            is_on_ = true;
            std::cout << engine_type() << " (" << horsepower_
                << " HP, " << battery_capacity_
                << " kWh battery) silently powers on.\n";
        }
        else {
            std::cout << engine_type() << " is already running.\n";
        }
    }

    void ElectricMotor::Stop() {
        if (is_on_) {
            is_on_ = false;
            std::cout << engine_type() << " powers down silently.\n";
        }
        else {
            std::cout << engine_type() << " is already off.\n";
        }
    }

    std::string ElectricMotor::engine_type() const {
        return "Electric Motor";
    }

}