#ifndef TASK6_MANUAL_GEARS_H_
#define TASK6_MANUAL_GEARS_H_

#include "gears.h"

namespace car::component {

	class ManualGears : public Gears {
	public:
		ManualGears();

		void ShiftUp() override;
		void ShiftDown() override;
		std::string gears_type() const override;

	private:
		bool clutch_engaged_;
	};

}

#endif  // TASK6_MANUAL_GEARS_H_
