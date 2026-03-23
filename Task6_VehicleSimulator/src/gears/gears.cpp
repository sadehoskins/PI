#include "gears.h"

namespace car::component {

    Gears::Gears(int max_gears) : max_gears_(max_gears) {}

    void Gears::ShiftUp() {
        if (current_gear_ < max_gears_) {
            ++current_gear_;
            std::cout << gears_type() << " shifted up to gear "
                << current_gear_ << ".\n";
        }
        else {
            std::cout << gears_type() << " already in highest gear.\n";
        }
    }

    void Gears::ShiftDown() {
        if (current_gear_ > 0) {
            --current_gear_;
            std::cout << gears_type() << " shifted down to gear "
                << current_gear_ << ".\n";
        }
        else {
            std::cout << gears_type() << " already in neutral.\n";
        }
    }

    double Gears::gear_ratio() const {
        if (current_gear_ == 0) return 0.0;
        // Higher gears = lower ratio, simulating real gear ratios
        return static_cast<double>(max_gears_ - current_gear_ + 1) /
            max_gears_;
    }

}