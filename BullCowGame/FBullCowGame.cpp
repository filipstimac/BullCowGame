#include "FBullCowGame.h"
#include <iostream>

using int32 = int;

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

//receives valid guess, increments try, returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment try number
	MyCurrentTry++;
	//setup return value
	FBullCowCount BullCowCount;
	//loop trough all letters
		//compare letters against hidden word
			//if they match then
				//icrmeent bulls if in same place, increment cows if not

	for (int32 i = 0; i < MyHiddenWord.length(); i++) {
		for (int32 j = 0; j < MyHiddenWord.length(); j++) {
			if (Guess[i] == MyHiddenWord[j]) {
				if (i == j) BullCowCount.Bulls++;
				else BullCowCount.Cows++;
			}
		}
	}
	return BullCowCount;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) return EGuessStatus::Not_Isogram;
	else if (false) return EGuessStatus::Not_Lowercase;
	else if (Guess.length() != GetHiddenWordLength()) return EGuessStatus::Wrong_Length;
	else return EGuessStatus::OK;
}
