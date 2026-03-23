#include "drum_brakes.h"

namespace car::component {

    DrumBrakes::DrumBrakes() : Brakes(60), drum_diameter_(280.0) {}

    void DrumBrakes::Apply() {
        if (!is_applied_) {
            is_applied_ = true;
            std::cout << brake_type() << " (" << drum_diameter_
                << " mm drums) engaged.\n";
        }
        else {
            std::cout << brake_type() << " already applied.\n";
        }
    }

    void DrumBrakes::Release() {
        if (is_applied_) {
            is_applied_ = false;
            std::cout << brake_type() << " released.\n";
        }
        else {
            std::cout << brake_type() << " already released.\n";
        }
    }

    std::string DrumBrakes::brake_type() const {
        return "Drum Brakes";
    }

}