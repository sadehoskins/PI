#ifndef TASK6_AUTOMATIC_GEARS_H_
#define TASK6_AUTOMATIC_GEARS_H_

#include "gears.h"

namespace car::component {

	class AutomaticGears : public Gears {
	public:
		AutomaticGears();

		void ShiftUp() override;
		void ShiftDown() override;
		std::string gears_type() const override;

	private:
		std::string mode_;
	};

}

#endif  // TASK6_AUTOMATIC_GEARS_H_
