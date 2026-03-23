#include "brakes.h"

namespace car::component {

    Brakes::Brakes(int braking_power) : braking_power_(braking_power) {}

    void Brakes::Apply() {
        if (!is_applied_) {
            is_applied_ = true;
            std::cout << brake_type() << " applied (braking power: "
                << braking_power_ << ").\n";
        }
        else {
            std::cout << brake_type() << " already applied.\n";
        }
    }

    void Brakes::Release() {
        if (is_applied_) {
            is_applied_ = false;
            std::cout << brake_type() << " released.\n";
        }
        else {
            std::cout << brake_type() << " already released.\n";
        }
    }

}