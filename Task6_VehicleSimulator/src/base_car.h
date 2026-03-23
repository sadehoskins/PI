#ifndef TASK6_BASE_CAR_H_
#define TASK6_BASE_CAR_H_

#include <iostream>
#include<memory>
#include <string>

#include "brakes/brakes.h"
#include "engine/engine.h"
#include "frame/frame.h"
#include "gears/gears.h"
#include "suspension/suspension.h"
#include "wheels/wheels.h"

// Base class defines interface for all car types
namespace car {

class BaseCar {
	public:
		BaseCar(std::shared_ptr<component::Engine> engine,
			std::shared_ptr<component::Gears> gears,
			std::shared_ptr<component::Wheels> wheels,
			std::shared_ptr<component::Brakes> brakes,
			std::shared_ptr<component::Frame> frame,
			std::shared_ptr<component::Suspension> suspension);
		virtual ~BaseCar() = default;

		virtual void Accelerate() = 0;
		virtual void Brake() = 0;
		virtual void ReverseAccelerate() = 0;

		// shared implementation
		void TurnLeft();
		void TurnRight();
		void StartEngine();
		void StopEngine();
		void PrintStatus();

		std::shared_ptr<component::Engine> engine() const {
			return engine_;
		}
		std::shared_ptr<component::Gears> gears() const {
			return gears_;
		}
		std::shared_ptr<component::Wheels> wheels() const {
			return wheels_;
		}
		std::shared_ptr<component::Brakes> brakes() const {
			return brakes_;
		}
		std::shared_ptr<component::Frame> frame() const {
			return frame_;
		}
		std::shared_ptr<component::Suspension> suspension() const {
			return suspension_;
		}
		
		virtual std::string car_type() const = 0;
		double current_speed() const { return current_speed_; }

	protected:
		// Calculate base acceleration
		double CalculateAcceleration() const;

		// Calculate stopping distance
		double CalculateStoppingDistance() const;

		std::shared_ptr<component::Engine> engine_;
		std::shared_ptr<component::Gears> gears_;
		std::shared_ptr<component::Wheels> wheels_;
		std::shared_ptr<component::Brakes> brakes_;
		std::shared_ptr<component::Frame> frame_;
		std::shared_ptr<component::Suspension> suspension_;
		double current_speed_ = 0.0;
		bool is_engine_on_ = false;
};

}	//namespace car

#endif	//TASK6_BASE_CAR_H
