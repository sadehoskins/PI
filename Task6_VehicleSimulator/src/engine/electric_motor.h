#ifndef TASK6_ELECTRIC_MOTOR_H_
#define TASK6_ELECTRIC_MOTOR_H_

#include "engine.h"

namespace car::component {

	class ElectricMotor : public Engine {
	public:
		ElectricMotor();

		void Start() override;
		void Stop() override;
		std::string engine_type() const override;

	private:
		double battery_capacity_;
	};

}  

#endif  // TASK6_ELECTRIC_MOTOR_H_
