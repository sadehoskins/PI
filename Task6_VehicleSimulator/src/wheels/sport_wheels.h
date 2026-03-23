#ifndef TASK6_SPORT_WHEELS_H_
#define TASK6_SPORT_WHEELS_H_

#include "wheels.h"

namespace car::component {

	class SportWheels : public Wheels {
	public:
		SportWheels();
		std::string wheel_type() const override;

	private:
		double grip_level_;
	};

}

#endif  // TASK6_SPORT_WHEELS_H_
