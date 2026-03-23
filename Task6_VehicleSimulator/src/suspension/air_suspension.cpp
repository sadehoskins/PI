#include "air_suspension.h"

namespace car::component {

    AirSuspension::AirSuspension()
        : Suspension(5.0, 120.0), ride_height_(220.0) {
    }

    std::string AirSuspension::suspension_type() const {
        return "Air Suspension (Ride Height: "
            + std::to_string(static_cast<int>(ride_height_)) + " mm)";
    }

}