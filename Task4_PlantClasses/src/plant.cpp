#include "plant.h"

#include <iostream>
#include <string>

Plant::Plant(const std::string& name, double growth_rate, float root_length,
    const std::string& leaf_color, float seed_diameter)
    : name_(name),
    growth_rate_(growth_rate),
    root_length_(root_length),
    leaf_color_(leaf_color),
    seed_diameter_(seed_diameter) {}

void Plant::DisplayInfo() const {
    std::cout << "=== Plant Info ===" << std::endl;
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Growth Rate: " << growth_rate_ << std::endl;
    std::cout << "Root Length: " << root_length_ << " cm" << std::endl;
    std::cout << "Leaf Color: " << leaf_color_ << std::endl;
    std::cout << "Seed Diameter: " << seed_diameter_ << " mm" << std::endl;
}

std::string Plant::name() const { return name_; }

double Plant::growth_rate() const { return growth_rate_; }

float Plant::root_length() const { return root_length_; }

std::string Plant::leaf_color() const { return leaf_color_; }

float Plant::seed_diameter() const { return seed_diameter_; }