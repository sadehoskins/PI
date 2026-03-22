#include "Grass.h"

#include <string>

Grass::Grass(const std::string& name, double growth_rate, float root_length,
	const std::string& leaf_color, float seed_diameter, double density)
	: Plant(name, growth_rate, root_length, leaf_color, seed_diameter),
	density_(density) {
}

double Grass::CalculateHeight(double t) const {
	// Linear growth
	return growth_rate() * t;
}