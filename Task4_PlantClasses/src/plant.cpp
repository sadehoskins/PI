#include "plant.h"

#include <iostream>
#include <string>

Plant::Plant(const std::string& name, double growth_rate, float root_lenght, const std::string& leaf_color,
	float seed_diameter)
	: name_(name), growth_rate_(growth_rate), root_length_(root_lenght), leaf_color_(leaf_color),
	seed_diameter_(seed_diameter) {}

void Plant::DisplayInfo() const {
	std::cout << "PLANT INFO" << std::endl;
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "Growth Rate: " << growth_rate_<< std::endl;
	std::cout << "Root Lenght: " << root_lenght_ << std::endl;
	std::cout << "Leaf Color: " << leaf_color_ << std::endl;
	std::cout << "Seed Diameter: " << seed_diameter_ << std::endl;
}

std::string Plant::name() const {
	return name_;
}

