#include "Shrub.h"

#include <cmath>
#include <string>

Shrub::Shrub(const std::string& name, double growth_rate, float root_length,
	const std::string& leaf_color, float seed_diameter, double spread)
	: Plant(name, growth_rate, root_length, leaf_color, seed_diameter),
	spread_(spread) {
}

double Shrub::CalculateHeight(double t) const {
	// Square-root growth: fast early, diminishes over time.
	// e.g. Gardenia: rate 0.4, at t=25 -> 0.4 * 5.0 = 2.0 m
	return growth_rate() * std::sqrt(t);
}