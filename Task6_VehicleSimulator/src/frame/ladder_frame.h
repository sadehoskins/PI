#ifndef TASK6_LADDER_FRAME_H_
#define TASK6_LADDER_FRAME_H_

#include "frame.h"

namespace car::component {

	class LadderFrame : public Frame {
	public:
		LadderFrame();
		std::string frame_type() const override;

	private:
		bool reinforced_;
	};

}

#endif  // TASK6_LADDER_FRAME_H_
