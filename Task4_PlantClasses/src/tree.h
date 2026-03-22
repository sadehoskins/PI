#ifndef TASK4_TREE_H_
#define TASK4_TREE_H_

#include <string>

#include "Plant.h"

class Tree : public Plant {
	public:
		Tree(const std::string& name, double growth_rate, float root_length, const std::string leaf_color, float seed_diameter, double max_height);

		double CalculateHeight(double t) const override;

	private:
		double max_height_;
};

#endif //	TASK4_TREE_H_


