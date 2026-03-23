#ifndef TASK6_FRAME_H_
#define TASK6_FRAME_H_

#include <iostream>
#include <string>

namespace car::component {

	// base class for frame types
	class Frame {
	public:
		Frame(const std::string& material, double weight_kg);
		virtual ~Frame() = default;

		std::string material() const { return material_; }
		double weight_kg() const { return weight_kg_; }
		virtual std::string frame_type() const = 0;

	protected:
		std::string material_;
		double weight_kg_;
	};

}

#endif  // TASK6_FRAME_H_
