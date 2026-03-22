#include "Tree.h"

#include <algorithm>
#include <string>

Tree::Tree(const std::string& name, double growth_rate, float root_lenght, const std::string leaf_color,
	float seed_diameter, double max_height)
	: Plant(name, growth_rate, root_lenght, leaf_color, seed_diameter),
	max_height_(max_height) {}

double Tree::CalculateHeight(double t) const {
	// Linear growth clamped to plant tree max
	return std::min(growth_rate() * t, max_height_); 
}