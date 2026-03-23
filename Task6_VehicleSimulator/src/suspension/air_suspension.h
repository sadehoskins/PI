#ifndef TASK6_AIR_SUSPENSION_H_
#define TASK6_AIR_SUSPENSION_H_

#include "suspension.h"

namespace car::component {

	class AirSuspension : public Suspension {
	public:
		AirSuspension();
		std::string suspension_type() const override;

	private:
		double ride_height_;
	};

}

#endif  // TASK6_AIR_SUSPENSION_H_
