#ifndef TASK6_DRUM_BRAKES_H_
#define TASK6_DRUM_BRAKES_H_

#include "brakes.h"

namespace car::component {

	class DrumBrakes : public Brakes {
	public:
		DrumBrakes();

		void Apply() override;
		void Release() override;
		std::string brake_type() const override;

	private:
		double drum_diameter_;
	};

}

#endif  // TASK6_DRUM_BRAKES_H_
