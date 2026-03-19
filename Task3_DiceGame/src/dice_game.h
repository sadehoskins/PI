#ifndef TASK3_DICE_GAME_H
#define TASK3_DICE_GAME_H

class DiceGame {
public:
	explicit DiceGame(int sides = 6);	// default 6-sided dice
	void GameStartInfo() const;
	void GameRound();
	void ShowScore() const;
	void ChangeDice(int new_sides);

	// Accessors
	int sides() const;
	bool is_running() const;
	void Quit();

private:
	int sides_;
	int player_score_;
	int computer_score_;
	bool is_running_;
	
};

#endif // TASK3_DICE_GAME_H
