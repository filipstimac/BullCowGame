#pragma once
#include<string>

class FBullCowGame {
public:
	void Reset(); //TODO return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string); // TODO return value

private:

};