#include "engine.h"

namespace car::component {

    Engine::Engine(int horsepower, int max_speed)
        : horsepower_(horsepower), max_speed_(max_speed) {
    }

    void Engine::Start() {
        if (!is_on_) {
            is_on_ = true;
            std::cout << engine_type() << " (" << horsepower_
                << " HP) started.\n";
        }
        else {
            std::cout << engine_type() << " is already running.\n";
        }
    }

    void Engine::Stop() {
        if (is_on_) {
            is_on_ = false;
            std::cout << engine_type() << " stopped.\n";
        }
        else {
            std::cout << engine_type() << " is already off.\n";
        }
    }

}