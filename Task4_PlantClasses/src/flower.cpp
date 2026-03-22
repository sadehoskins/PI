#include "Flower.h"

#include <cmath>
#include <string>

Flower::Flower(const std::string& name, double growth_rate, float root_length,
	const std::string& leaf_color, float seed_diameter, double bloom_height)
	: Plant(name, growth_rate, root_length, leaf_color, seed_diameter),
	bloom_height_(bloom_height) {
}

double Flower::CalculateHeight(double t) const {
	// Asymptotic growth: approaches bloom_height_ but never exceeds it.
	// e.g. Hydrangea: rate 0.5, bloom 1.8 m -> rises quickly then plateaus.
	return bloom_height_ * (1.0 - std::exp(-growth_rate() * t));
}