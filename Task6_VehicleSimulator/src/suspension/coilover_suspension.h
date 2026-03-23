#ifndef TASK6_COILOVER_SUSPENSION_H_
#define TASK6_COILOVER_SUSPENSION_H_

#include "suspension.h"

namespace car::component {

	class CoiloverSuspension : public Suspension {
	public:
		CoiloverSuspension();
		std::string suspension_type() const override;

	private:
		bool adjustable_;
	};

} 

#endif  // TASK6_COILOVER_SUSPENSION_H_
