#include "sport_wheels.h"

namespace car::component {

    SportWheels::SportWheels()
        : Wheels(0.95, 18.0), grip_level_(9.2) {
    }

    std::string SportWheels::wheel_type() const {
        return "Sport Wheels (18\")";
    }

}