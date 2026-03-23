#include "sports_car.h"

#include <cmath>
#include <iomanip>

#include "engine/v6_engine.h"
#include "gears/manual_gears.h"
#include "wheels/sport_wheels.h"
#include "brakes/disc_brakes.h"
#include "frame/monocoque_frame.h"
#include "suspension/coilover_suspension.h"

namespace car {

    SportsCar::SportsCar()
        : BaseCar(std::make_shared<component::V6Engine>(),
            std::make_shared<component::ManualGears>(),
            std::make_shared<component::SportWheels>(),
            std::make_shared<component::DiscBrakes>(),
            std::make_shared<component::MonocoqueFrame>(),
            std::make_shared<component::CoiloverSuspension>()),
        turbo_boost_(1.0) {
    }

    void SportsCar::Accelerate() {
        if (!is_engine_on_) {
            std::cout << car_type() << " cannot accelerate. Engine is off.\n";
            return;
        }
        if (brakes_->is_applied()) {
            brakes_->Release();
        }

        double accel = CalculateAcceleration() * turbo_boost_;
        // Simulate 1 second of acceleration, convert to km/h.
        double speed_gain = accel * 3.6;
        double max_speed = static_cast<double>(engine_->max_speed());
        current_speed_ = std::min(current_speed_ + speed_gain, max_speed);

        std::cout << car_type() << " accelerates forward at "
            << std::fixed << std::setprecision(2) << accel
            << " m/s^2 (Engine: " << engine_->horsepower()
            << " HP, Wheels: " << wheels_->wheel_type()
            << ", traction: " << wheels_->traction() << ").\n"
            << "Current speed: " << std::setprecision(1)
            << current_speed_ << " km/h.\n";
    }

    void SportsCar::Brake() {
        if (current_speed_ <= 0.0) {
            std::cout << car_type() << " is already stopped.\n";
            return;
        }

        double stopping_dist = CalculateStoppingDistance();
        brakes_->Apply();

        std::cout << car_type() << " brakes and took "
            << std::fixed << std::setprecision(1)
            << stopping_dist << " meters to stop"
            << " (Brakes: " << brakes_->brake_type()
            << ", power: " << brakes_->braking_power()
            << ", Wheels traction: " << wheels_->traction()
            << ").\n";

        current_speed_ = 0.0;
    }

    void SportsCar::ReverseAccelerate() {
        if (!is_engine_on_) {
            std::cout << car_type()
                << " cannot reverse. Engine is off.\n";
            return;
        }
        if (current_speed_ > 0.0) {
            std::cout << car_type()
                << " must stop before reversing.\n";
            return;
        }
        if (brakes_->is_applied()) {
            brakes_->Release();
        }

        // Reverse at reduced acceleration (40% of forward).
        double accel = CalculateAcceleration() * 0.4;
        double speed_gain = accel * 3.6;
        double max_reverse = 30.0;
        current_speed_ = std::min(current_speed_ + speed_gain, max_reverse);

        std::cout << car_type() << " reverses at "
            << std::fixed << std::setprecision(2) << accel
            << " m/s^2 (Engine: " << engine_->horsepower()
            << " HP, Wheels traction: " << wheels_->traction()
            << ").\n"
            << "Reverse speed: " << std::setprecision(1)
            << current_speed_ << " km/h.\n";
    }

    void SportsCar::ActivateTurbo() {
        if (turbo_boost_ > 1.0) {
            turbo_boost_ = 1.0;
            std::cout << car_type() << " turbo deactivated.\n";
        }
        else {
            turbo_boost_ = 1.35;
            std::cout << car_type()
                << " turbo activated! (+35% boost)\n";
        }
    }

    std::string SportsCar::car_type() const {
        return "SportsCar";
    }

}  // namespace car