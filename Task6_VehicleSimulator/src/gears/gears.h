#ifndef TASK6_GEARS_H_
#define TASK6_GEARS_H_

#include <iostream>
#include <string>

namespace car::component {

	// base class for transmission types
	class Gears {
	public:
		Gears(int max_gears);
		virtual ~Gears() = default;

		virtual void ShiftUp();
		virtual void ShiftDown();

		int current_gear() const { return current_gear_; }
		int max_gears() const { return max_gears_; }

		// Returns a gear ratio multiplier -> affects acceleration
		double gear_ratio() const;

		virtual std::string gears_type() const = 0;

	protected:
		int current_gear_ = 0;
		int max_gears_;
	};

}

#endif  // TASK6_GEARS_H_
