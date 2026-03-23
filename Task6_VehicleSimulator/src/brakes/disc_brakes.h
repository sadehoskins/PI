#ifndef TASK6_DISC_BRAKES_H_
#define TASK6_DISC_BRAKES_H_

#include "brakes.h"

namespace car::component {

	class DiscBrakes : public Brakes {
	public:
		DiscBrakes();

		void Apply() override;
		void Release() override;
		std::string brake_type() const override;

	private:
		double disc_size_;
	};

}

#endif  // TASK6_DISC_BRAKES_H_