#ifndef TASK6_V6_ENGINE_H_
#define TASK6_V6_ENGINE_H_

#include "engine.h"

namespace car::component {

	class V6Engine : public Engine {
	public:
		V6Engine();

		void Start() override;
		void Stop() override;
		std::string engine_type() const override;

	private:
		int cylinder_count_;
	};
} 

#endif  // TASK6_V6_ENGINE_H_
