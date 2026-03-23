#ifndef TASK6_SPORTS_CAR_H_
#define TASK6_SPORTS_CAR_H_

#include "base_car.h"

namespace car {

	class SportsCar : public BaseCar {
	public:
		SportsCar();

		void Accelerate() override;
		void Brake() override;
		void ReverseAccelerate() override;
		void ActivateTurbo();

		std::string car_type() const override;

	private:
		double turbo_boost_;
	};

}  // namespace car

#endif  // TASK6_SPORTS_CAR_H_