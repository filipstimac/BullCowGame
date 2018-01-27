#pragma once
#include<string>

class FBullCowGame {
public:
	FBullCowGame();

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(std::string); // TODO return value
	void Reset(); //TODO return value
				  // provide a method for counting bulls and cows and incrementing turn number

private:
	int MyMaxTries;
	int MyCurrentTry;

};