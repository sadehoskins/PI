#include "v6_engine.h"

namespace car::component {

    V6Engine::V6Engine() : Engine(300, 250), cylinder_count_(6) {}

    void V6Engine::Start() {
        if (!is_on_) {
            is_on_ = true;
            std::cout << engine_type() << " (" << cylinder_count_
                << " cylinders, " << horsepower_ << " HP) roars to life.\n";
        }
        else {
            std::cout << engine_type() << " is already running.\n";
        }
    }

    void V6Engine::Stop() {
        if (is_on_) {
            is_on_ = false;
            std::cout << engine_type() << " rumbles to a stop.\n";
        }
        else {
            std::cout << engine_type() << " is already off.\n";
        }
    }

    std::string V6Engine::engine_type() const {
        return "V6 Engine";
    }

}