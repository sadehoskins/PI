#include "disc_brakes.h"

namespace car::component {

    DiscBrakes::DiscBrakes() : Brakes(85), disc_size_(350.0) {}

    void DiscBrakes::Apply() {
        if (!is_applied_) {
            is_applied_ = true;
            std::cout << brake_type() << " (" << disc_size_
                << " mm discs) clamped hard.\n";
        }
        else {
            std::cout << brake_type() << " already applied.\n";
        }
    }

    void DiscBrakes::Release() {
        if (is_applied_) {
            is_applied_ = false;
            std::cout << brake_type() << " released smoothly.\n";
        }
        else {
            std::cout << brake_type() << " already released.\n";
        }
    }

    std::string DiscBrakes::brake_type() const {
        return "Disc Brakes";
    }

}