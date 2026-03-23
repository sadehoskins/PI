#include "suspension.h"

namespace car::component {

    Suspension::Suspension(double stiffness, double travel_mm)
        : stiffness_(stiffness), travel_mm_(travel_mm) {
    }

    void Suspension::DriveOverHoles() {
        std::cout << suspension_type() << " absorbs bumps (travel: "
            << travel_mm_ << " mm, stiffness: " << stiffness_
            << ").\n";
    }

}