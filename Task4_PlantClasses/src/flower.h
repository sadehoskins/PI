#ifndef TASK4_FLOWER_H_
#define TASK4_FLOWER_H_

#include <string>

#include "Plant.h"

class Flower : public Plant {
public:
	Flower(const std::string& name, double growth_rate, float root_length,
		const std::string& leaf_color, float seed_diameter, double bloom_height);

	double CalculateHeight(double t) const override;

private:
	double bloom_height_;
};


#endif // TASK4_FLOWER_H_
