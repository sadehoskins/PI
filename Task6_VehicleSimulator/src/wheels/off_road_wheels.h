#ifndef TASK6_OFF_ROAD_WHEELS_H_
#define TASK6_OFF_ROAD_WHEELS_H_

#include "wheels.h"

namespace car::component {

	class OffRoadWheels : public Wheels {
	public:
		OffRoadWheels();
		std::string wheel_type() const override;

	private:
		int mud_rating_;
	};

}

#endif  // TASK6_OFF_ROAD_WHEELS_H_
