#include "coilover_suspension.h"

namespace car::component {

    CoiloverSuspension::CoiloverSuspension()
        : Suspension(8.5, 80.0), adjustable_(true) {
    }

    std::string CoiloverSuspension::suspension_type() const {
        return "Coilover Suspension (Adjustable)";
    }

}