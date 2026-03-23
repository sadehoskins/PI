#include "base_car.h"

#include <cmath>
#include <iomanip>

namespace car {

    BaseCar::BaseCar(std::shared_ptr<component::Engine> engine,
        std::shared_ptr<component::Gears> gears,
        std::shared_ptr<component::Wheels> wheels,
        std::shared_ptr<component::Brakes> brakes,
        std::shared_ptr<component::Frame> frame,
        std::shared_ptr<component::Suspension> suspension)
        : engine_(std::move(engine)),
        gears_(std::move(gears)),
        wheels_(std::move(wheels)),
        brakes_(std::move(brakes)),
        frame_(std::move(frame)),
        suspension_(std::move(suspension)) {
    }

    void BaseCar::TurnLeft() {
        if (!is_engine_on_) {
            std::cout << car_type() << " cannot turn. Engine is off.\n";
            return;
        }
        std::cout << car_type() << " turns left.\n";
    }

    void BaseCar::TurnRight() {
        if (!is_engine_on_) {
            std::cout << car_type() << " cannot turn. Engine is off.\n";
            return;
        }
        std::cout << car_type() << " turns right.\n";
    }

    void BaseCar::StartEngine() {
        if (is_engine_on_) {
            std::cout << car_type() << " engine is already running.\n";
            return;
        }
        engine_->Start();
        is_engine_on_ = true;
        // Auto-shift into first gear on engine start.
        if (gears_->current_gear() == 0) {
            gears_->ShiftUp();
        }
    }

    void BaseCar::StopEngine() {
        if (!is_engine_on_) {
            std::cout << car_type() << " engine is already off.\n";
            return;
        }
        if (current_speed_ > 0.0) {
            std::cout << "Warning: " << car_type()
                << " is still moving at " << std::fixed
                << std::setprecision(1) << current_speed_
                << " km/h! Brake first.\n";
            return;
        }
        engine_->Stop();
        is_engine_on_ = false;
        // Reset gear to neutral.
        while (gears_->current_gear() > 0) {
            gears_->ShiftDown();
        }
    }

    void BaseCar::PrintStatus() {
        std::cout << "\n++++++++++++++++++ " << car_type() << " Status ++++++++++++++++++\n"
            << "Engine:     " << engine_->engine_type()
            << " (" << engine_->horsepower() << " HP)"
            << (is_engine_on_ ? " [ON]" : " [OFF]") << "\n"
            << "Gears:      " << gears_->gears_type()
            << " [Gear " << gears_->current_gear() << "]\n"
            << "Wheels:     " << wheels_->wheel_type()
            << " (traction: " << wheels_->traction() << ")\n"
            << "Brakes:     " << brakes_->brake_type()
            << " (power: " << brakes_->braking_power() << ")\n"
            << "Frame:      " << frame_->frame_type()
            << " (" << frame_->weight_kg() << " kg)\n"
            << "Suspension: " << suspension_->suspension_type()
            << "\n"
            << "Speed:      " << std::fixed << std::setprecision(1)
            << current_speed_ << " km/h\n";
    }

    double BaseCar::CalculateAcceleration() const {
        // a = (HP * 745.7 * traction * gear_ratio) / (weight * 100)
        // Simplified model using component attributes
        double power_watts = engine_->horsepower() * 745.7;
        double traction = wheels_->traction();
        double ratio = gears_->gear_ratio();
        double weight = frame_->weight_kg();

        if (weight <= 0.0 || ratio <= 0.0) return 0.0;

        return (power_watts * traction * ratio) / (weight * 100.0);
    }

    double BaseCar::CalculateStoppingDistance() const {
        // d = v^2 / (2 * brake_decel)
        // brake_decel = (braking_power * traction) / 10
        if (current_speed_ <= 0.0) return 0.0;

        double speed_ms = current_speed_ / 3.6;
        double brake_decel =
            (brakes_->braking_power() * wheels_->traction()) / 10.0;

        if (brake_decel <= 0.0) return 0.0;
        return (speed_ms * speed_ms) / (2.0 * brake_decel);
    }

}  // namespace car