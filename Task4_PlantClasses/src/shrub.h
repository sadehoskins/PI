#ifndef TASK4_SHRUB_H_
#define TASK4_SHRUB_H_

#include <string>

#include "Plant.h"

class Shrub : public Plant {
public:
	Shrub(const std::string& name, double growth_rate, float root_length,
		const std::string& leaf_color, float seed_diameter, double spread);

	double CalculateHeight(double t) const override;

private:
	double spread_;
};

#endif // TASK4_SHRUB_H_
