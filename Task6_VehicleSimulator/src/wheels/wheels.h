#ifndef TASK6_WHEELS_H_
#define TASK6_WHEELS_H_

#include <iostream>
#include <string>

namespace car::component {

	// base class wheel types
	class Wheels {
	public:
		Wheels(double traction, double diameter);
		virtual ~Wheels() = default;

		double traction() const { return traction_; }
		double diameter() const { return diameter_; }
		virtual std::string wheel_type() const = 0;

	protected:
		double traction_;
		double diameter_;
	};

}

#endif  // TASK6_WHEELS_H_
