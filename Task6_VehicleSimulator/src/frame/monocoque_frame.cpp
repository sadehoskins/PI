#include "monocoque_frame.h"

namespace car::component {

    MonocoqueFrame::MonocoqueFrame()
        : Frame("Carbon Fiber Composite", 120.0), carbon_fiber_(true) {
    }

    std::string MonocoqueFrame::frame_type() const {
        return "Monocoque Frame (Carbon Fiber)";
    }

}