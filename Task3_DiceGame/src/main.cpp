#include "dice_game.h"

#include <iostream>
#include <limits>

namespace {
	// Prompts the user to select dic sides (6, 10 or 20). Repeats until valid input
	int PromptForSides() {
		int sides = 0;
		while (true) {
			std::cout << "Choose dice sides (6, 10 or 20). ";
			std::cin >> sides;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. Enter a number! \n";
				continue;
			}

			if (sides == 6 || sides == 10 || sides == 20) {
				return sides;
			}
			std::cout << "Invalid choice. Pick 6, 10 or 20.\n";
		}
	}
}	// namespace

int main() {
	int initial_sides = PromptForSides();
	DiceGame game(initial_sides);
	game.GameStartInfo(); 

	while (game.is_running()) {
		std::cout << "\n[R]oll | [C]hange dice | [Q]uit ";
		char choice = '\0';

		switch 
	}
}