#include "suv.h"

#include <cmath>
#include <iomanip>

#include "engine/electric_motor.h"
#include "gears/automatic_gears.h"
#include "wheels/off_road_wheels.h"
#include "brakes/drum_brakes.h"
#include "frame/ladder_frame.h"
#include "suspension/air_suspension.h"

namespace car {

    Suv::Suv()
        : BaseCar(std::make_shared<component::ElectricMotor>(),
            std::make_shared<component::AutomaticGears>(),
            std::make_shared<component::OffRoadWheels>(),
            std::make_shared<component::DrumBrakes>(),
            std::make_shared<component::LadderFrame>(),
            std::make_shared<component::AirSuspension>()),
        four_wheel_drive_(false) {
    }

    void Suv::Accelerate() {
        if (!is_engine_on_) {
            std::cout << car_type() << " cannot accelerate. Engine is off.\n";
            return;
        }
        if (brakes_->is_applied()) {
            brakes_->Release();
        }

        double accel = CalculateAcceleration();
        // 4WD has 20% traction bonus
        if (four_wheel_drive_) {
            accel *= 1.2;
        }
        double speed_gain = accel * 3.6;
        double max_speed = static_cast<double>(engine_->max_speed());
        current_speed_ = std::min(current_speed_ + speed_gain, max_speed);

        std::cout << car_type() << " accelerates forward at "
            << std::fixed << std::setprecision(2) << accel
            << " m/s^2 (Engine: " << engine_->horsepower()
            << " HP, Wheels: " << wheels_->wheel_type()
            << ", traction: " << wheels_->traction()
            << (four_wheel_drive_ ? ", 4WD active" : "")
            << ").\n"
            << "Current speed: " << std::setprecision(1)
            << current_speed_ << " km/h.\n";
    }

    void Suv::Brake() {
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

    void Suv::ReverseAccelerate() {
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

        double accel = CalculateAcceleration() * 0.4;
        if (four_wheel_drive_) {
            accel *= 1.2;
        }
        double speed_gain = accel * 3.6;
        double max_reverse = 25.0;
        current_speed_ = std::min(current_speed_ + speed_gain, max_reverse);

        std::cout << car_type() << " reverses at "
            << std::fixed << std::setprecision(2) << accel
            << " m/s^2 (Engine: " << engine_->horsepower()
            << " HP, Wheels traction: " << wheels_->traction()
            << (four_wheel_drive_ ? ", 4WD active" : "")
            << ").\n"
            << "Reverse speed: " << std::setprecision(1)
            << current_speed_ << " km/h.\n";
    }

    void Suv::ToggleFourWheelDrive() {
        four_wheel_drive_ = !four_wheel_drive_;
        std::cout << car_type() << " 4WD "
            << (four_wheel_drive_ ? "engaged" : "disengaged")
            << ".\n";
    }

    std::string Suv::car_type() const {
        return "SUV";
    }

} 