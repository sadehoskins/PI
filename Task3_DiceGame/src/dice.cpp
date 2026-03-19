#include "dice.h"

#include <random>

int RollDice(int sides) {
	static thread_local std::mt19937 generator{ std::random_device{}() };
	std::uniform_int_distribution<int> distribution(1, sides);
	return distribution(generator);
}