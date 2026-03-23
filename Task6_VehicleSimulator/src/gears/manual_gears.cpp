#include "manual_gears.h"

namespace car::component {

	ManualGears::ManualGears() : Gears(6), clutch_engaged_(false) {}

	void ManualGears::ShiftUp() {
		clutch_engaged_ = true;
		Gears::ShiftUp();
		clutch_engaged_ = false;
	}

	void ManualGears::ShiftDown() {
		clutch_engaged_ = true;
		Gears::ShiftDown();
		clutch_engaged_ = false;
	}

	std::string ManualGears::gears_type() const {
		return "6-Speed Manual";
	}

}