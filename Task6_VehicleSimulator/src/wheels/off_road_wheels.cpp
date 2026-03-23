#include "off_road_wheels.h"

namespace car::component {

    OffRoadWheels::OffRoadWheels()
        : Wheels(0.75, 20.0), mud_rating_(8) {
    }

    std::string OffRoadWheels::wheel_type() const {
        return "Off-Road Wheels (20\")";
    }

}