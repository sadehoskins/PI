#ifndef TASK6_MONOCOQUE_FRAME_H_
#define TASK6_MONOCOQUE_FRAME_H_

#include "frame.h"

namespace car::component {

	class MonocoqueFrame : public Frame {
	public:
		MonocoqueFrame();
		std::string frame_type() const override;

	private:
		bool carbon_fiber_;
	};

}

#endif  // TASK6_MONOCOQUE_FRAME_H_
