#ifndef TASK6_BRAKES_H_
#define TASK6_BRAKES_H_

#include <iostream>
#include <string>

namespace car::component {

	// base class brake types
	class Brakes {
	public:
		Brakes(int braking_power);
		virtual ~Brakes() = default;

		virtual void Apply();
		virtual void Release();

		bool is_applied() const { return is_applied_; }
		int braking_power() const { return braking_power_; }
		virtual std::string brake_type() const = 0;

	protected:
		int braking_power_;
		bool is_applied_ = false;
	};

}

#endif  // TASK6_BRAKES_H_
