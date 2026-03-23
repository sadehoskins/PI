#ifndef TASK6_SUV_H_
#define TASK6_SUV_H_

#include "base_car.h"

namespace car {

	class Suv : public BaseCar {
	public:
		Suv();

		void Accelerate() override;
		void Brake() override;
		void ReverseAccelerate() override;
		void ToggleFourWheelDrive();

		std::string car_type() const override;

	private:
		bool four_wheel_drive_;
	};

}  // namespace car

#endif  // TASK6_SUV_H_
