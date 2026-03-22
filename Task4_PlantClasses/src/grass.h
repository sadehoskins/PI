#ifndef TASK4_GRASS_H_
#define TASK4_GRASS_H_

#include <string>

#include "Plant.h"

class Grass : public Plant {
public:
	Grass(const std::string& name, double growth_rate, float root_length,
		const std::string& leaf_color, float seed_diameter, double density);

	double CalculateHeight(double t) const override;

private:
	double density_;
};

#endif // TASK4_GRASS_H_
