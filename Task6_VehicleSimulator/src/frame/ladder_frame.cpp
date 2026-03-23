#include "ladder_frame.h"

namespace car::component {

    LadderFrame::LadderFrame()
        : Frame("High-Strength Steel", 250.0), reinforced_(true) {
    }

    std::string LadderFrame::frame_type() const {
        return "Ladder Frame (Reinforced Steel)";
    }

}