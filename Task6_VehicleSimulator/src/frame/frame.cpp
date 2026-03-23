#include "frame.h"

namespace car::component {

    Frame::Frame(const std::string& material, double weight_kg)
        : material_(material), weight_kg_(weight_kg) {
    }

}