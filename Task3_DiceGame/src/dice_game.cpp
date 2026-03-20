#include "dice_game.h"

#include <iostream>

#include "dice.h"

DiceGame::DiceGame(int sides) : sides_(sides), player_score_(0), computer_score_(0), is_running_(true) {}

void DiceGame::GameStartInfo() const {
	std::cout << "Welcome to DICE GAME!\n"
		<< "You play against the computer.\n"
		<< "Each round, you will roll a dice and the computer will roll a dice.\n"
		<< "The one with the higher roll wins the round and gets points.\n"
		<< "You can change the number of sides on the dice at any time.\n"
		<< "Let's start the game!\n"
		<< "Options: [R]oll, [C]hange dice, [Q]uit\n\n";
}

void DiceGame::GameRound() {
	int player_roll = RollDice(sides_);
	int computer_roll = RollDice(sides_);

	std::cout << "You rolled: " << player_roll 
		<< " | Computer rolled: " << computer_roll << "\n";

	// Determine round winner
	if (player_roll > computer_roll) {
		++player_score_;
		std::cout << "Congrats! You win this round.\n";
	}
	else if (computer_roll > player_roll) {
		++computer_score_;
		std::cout << "Computer wins this round. \n";
	}
	else {
		std::cout << "It's a tie!\n";
	}
}

void DiceGame::ShowScore() const {
	std::cout << "Your Score: " << player_score_
		<< " | Computer Score: " << computer_score_ << "\n";
}

void DiceGame::ChangeDice(int new_sides) {
	sides_ = new_sides;
	std::cout << "Dice changed to " << sides_ << " sides.\n";
}

int DiceGame::sides() const { 
	return sides_; 
}

bool DiceGame::is_running() const {
	return is_running_;
}

void DiceGame::Quit() {
	is_running_ = false;
}