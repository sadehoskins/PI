#ifndef TASK6_SUSPENSION_H_
#define TASK6_SUSPENSION_H_

#include <iostream>
#include <string>

namespace car::component {

	//  base class for suspension types
	class Suspension {
	public:
		Suspension(double stiffness, double travel_mm);
		virtual ~Suspension() = default;

		double stiffness() const { return stiffness_; }
		double travel_mm() const { return travel_mm_; }
		virtual std::string suspension_type() const = 0;

		void DriveOverHoles();

	protected:
		double stiffness_;
		double travel_mm_;
	};

}

#endif  // TASK6_SUSPENSION_H_
