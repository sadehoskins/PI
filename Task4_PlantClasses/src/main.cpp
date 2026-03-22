#include <iostream>
#include <limits>
#include <string>

#include "plant.h"
#include "tree.h"
#include "flower.h"
#include "shrub.h"
#include "grass.h"

// user validation: positive double
// no negative numbers & no non-numeric -> loops until valid
double ReadPositiveDouble(const std::string& prompt) {
	double value = 0.0;
	while (true) {
		std::cout << prompt;
		std::cin >> value;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << " Invalid number. Please enter number!" << std::endl;

		}
		else if (value < 0.0) {
			std::cout << "No negative number allowed! Please enter positive number!" << std::endl;
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return value;
		}
	}
}

// user validation: int (min_val, mal_val)
// loops until valid
int ReadIntInRange(const std::string& prompt, int min_val, int max_val) {
	int value = 0;
	while (true) {
		std::cout << prompt;
		std::cin >> value;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (value < min_val || value > max_val) {
			std::cout << "Invalid input. Please choose a number between " << min_val << "and " << max_val << "!" << std::endl;
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return value;
		}
	}
}

// Create TREE based on species choice (Cherry Tree, Maple, Oak)
Plant* CreateTree() {
	std::cout <<  "*** TREE SPECIES *** " << std::endl;
	std::cout << "[1] Cherry Tree" << std::endl;
	std::cout << "[2] Maple" << std::endl;
	std::cout << "[3] Oak" << std::endl;
	int choice = ReadIntInRange("Select species: ", 1, 3);

	switch (choice) {
	case 1: 
		return new Tree("Cherry", 0.5, 3.0f, "green", 1.0f, 15.0);
	case 2: 
		return new Tree("Maple", 0.6, 4.0f, "orange", 0.8f, 25.0);
	case 3:
		return new Tree("Oak", 0.4, 6.0f, "green", 2.5f, 30.0);
	default: return nullptr;
	}
}

// Create FLOWER based on species choice (Hydrangea, Hibiscus, Lavender)
Plant* CreateFlower() {
	std::cout << "\n*** FLOWER SPECIES *** " << std::endl;
	std::cout << "[1] Hydrangea" << std::endl;
	std::cout << "[2] Hibiscus" << std::endl;
	std::cout << "[3] Lavender" << std::endl;
	int choice = ReadIntInRange("Select species: ", 1, 3);

	switch (choice) {
	case 1: 
		return new Flower("Hydrangea", 0.5, 1.5f, "blue", 0.3f, 1.8);
	case 2: 
		return new Flower("Hibiscus", 0.6, 2.0f, "red", 0.4f, 2.5);
	case 3: 
		return new Flower("Lavender", 0.8, 1.0f, "purple", 0.2f, 0.9);
	default: return nullptr;
	}
}

// Create SHRUB based on species choice (Gardenia, Rhododendron, Azalea)
Plant* CreateShrub() {
	std::cout << "\n*** SHRUB SPECIES *** " << std::endl;
	std::cout << "[1] Gardenia" << std::endl;
	std::cout << "[2] Rhododendron" << std::endl;
	std::cout << "[3] Azalea" << std::endl;
	int choice = ReadIntInRange("Select species: ", 1, 3);

	switch (choice) {
	case 1: 
		return new Shrub("Gardenia", 0.4, 2.0f, "green", 0.5f, 1.5);
	case 2: 
		return new Shrub("Rhododendron", 0.3, 3.0f, "green", 0.3f, 2.0);
	case 3: 
		return new Shrub("Azalea", 0.35, 2.5f, "pink", 0.4f, 1.8);
	default: return nullptr;
	}
}

// Create GRASS based on species choice (Pampas, Lemongrass, Napier Grass)
Plant* CreateGrass() {
	std::cout << "\n*** GRASS SPECIES ***" << std::endl;
	std::cout << "[1] Pampas Grass" << std::endl;
	std::cout << "[2] Lemongrass" << std::endl;
	std::cout << "[3] Napier Grass" << std::endl;
	int choice = ReadIntInRange("Select species: ", 1, 3);

	switch (choice) {
	case 1: 
		return new Grass("Pampas Grass", 0.3, 2.5f, "silver", 0.2f, 0.8);
	case 2: 
		return new Grass("Lemongrass", 0.25, 1.5f, "green", 0.1f, 0.6);
	case 3: 
		return new Grass("Napier Grass", 0.5, 3.0f, "green", 0.15f, 0.9);
	default: return nullptr;
	}
}

// GAME LOOP
int main() {
	std::cout << "..........PLANT GROWTH INFO SYSTEM.........." << std::endl;
	std::cout << "Receive information about different plants and calculate their average growth height!" << std::endl;

	Plant* plant = nullptr;
	bool running = true;

	while (running) {
		std::cout << "..........Select a plant type: .........." << std::endl;
		std::cout << "[1] Tree" << std::endl;
		std::cout << "[2] Flower" << std::endl;
		std::cout << "[3] Shrub" << std::endl;
		std::cout << "[4] Grass" << std::endl;
		std::cout << "[0] Quit" << std::endl;

		int type_choice = ReadIntInRange("Your choice: ", 0, 4);

		if (type_choice == 0) {
			running = false;
			continue;
		}

		// Clean up 
		delete plant;
		plant = nullptr;

		switch (type_choice) {
		case 1:
			plant = CreateTree();
			break;
		case 2:
			plant = CreateFlower();
			break;
		case 3:
			plant = CreateShrub();
			break;
		case 4:
			plant = CreateGrass();
			break;
		}

		// Error code
		if (plant == nullptr) {
			std::cout << "Error creating plant." << std::endl;
			continue;
		}

		// Display base plant attributes
		std::cout << std::endl;
		plant->DisplayInfo();

		// Get grwoth time & caculate height
		double t = ReadPositiveDouble("\nEnter growth time t (years, >= 0)");
		double height = plant->CalculateHeight(t);
		std::cout << "\nAverage growth height of " << plant->name() << " = " << height << " meters" << std::endl;
	}

	// Clean up
	delete plant;

	std::cout << "\n See you next time! Goodbye!" << std::endl;
	return 0;
}