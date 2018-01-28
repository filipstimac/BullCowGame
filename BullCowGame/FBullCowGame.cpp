#pragma once
#include "FBullCowGame.h"
#include <iostream>
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ {3, 3}, {4, 7}, {5, 11}, {6, 16}, {7, 22}, {8, 29}, {9, 37}, {10, 46} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 10;
	const FString HIDDEN_WORD = "bodega";

	bIsGameWon = false;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

//receives valid guess, increments try, returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
	MyCurrentTry++;

	//setup return value
	FBullCowCount BullCowCount;

	for (int32 i = 0; i < MyHiddenWord.length(); i++) {
		for (int32 j = 0; j < MyHiddenWord.length(); j++) {
			if (Guess[i] == MyHiddenWord[j]) {
				if (i == j) BullCowCount.Bulls++;
				else BullCowCount.Cows++;
			}
		}
	}
	if (BullCowCount.Bulls == GetHiddenWordLength()) bIsGameWon = true;
	else bIsGameWon = false;
	return BullCowCount;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	if (!IsISogram(Guess)) return EGuessStatus::Not_Isogram;
	else if (!IsLowercase(Guess)) return EGuessStatus::Not_Lowercase;
	else if (Guess.length() != GetHiddenWordLength()) return EGuessStatus::Wrong_Length;
	else return EGuessStatus::OK;
}

bool FBullCowGame::IsISogram(FString Guess) const
{
	if (Guess.length() <= 1) return true;

	TMap<char, bool> LetterSeen;
	
	for (auto Letter : Guess) {
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) return false;
		else LetterSeen[Letter] = true;
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const
{
	if (Guess.length() == 0) return true;
	for (auto Letter : Guess) {
		if (isupper(Letter)) return false;
	}
	return true;
}
