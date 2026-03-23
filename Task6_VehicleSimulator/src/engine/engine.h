#ifndef TASK6_ENGINE_H_
#define TASK6_ENGINE_H_

#include <iostream>
#include <string>

namespace car::component {

	// base class for all engine types
	// interface for starting/stopping & engine specs
	class Engine {
	public:
		Engine(int horsepower, int max_speed);
		virtual ~Engine() = default;

		virtual void Start();
		virtual void Stop();

		bool is_on() const { return is_on_; }
		int horsepower() const { return horsepower_; }
		int max_speed() const { return max_speed_; }
		virtual std::string engine_type() const = 0;

	protected:
		int horsepower_;
		int max_speed_;
		bool is_on_ = false;
	};

}

#endif  // TASK6_ENGINE_H_