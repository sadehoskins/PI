#include "automatic_gears.h"

namespace car::component {

	AutomaticGears::AutomaticGears() : Gears(8), mode_("Drive") {}

	void AutomaticGears::ShiftUp() {
		Gears::ShiftUp();
	}

	void AutomaticGears::ShiftDown() {
		Gears::ShiftDown();
	}

	std::string AutomaticGears::gears_type() const {
		return "8-Speed Automatic (" + mode_ + ")";
	}

}