/* This is console executable, that makes use of BullCow class
This acts as the view in MVC pattern, and is responsible  for all
user interaction. For  game logic see the FBullCowGame class.

*/

#pragma once
#include<iostream>
#include<string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void printIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
FBullCowGame BCGame;
void PrintGameSummary();

int main() {

	do {
		printIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}

/*
High level abstraction function with main game logic
*/
void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	while(!BCGame.IsGameWon() && (BCGame.GetCurrentTry() <= MaxTries)) {
		FText Guess = GetValidGuess();

		// submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls << ". Cows = " << BullCowCount.Cows << ".\n\n";
	}

	PrintGameSummary();
	return;
}

void printIntro() {
	//introduce the game
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl << std::endl;
	return;
}

/*
Receives guess from player and makes sure that guess is valid (all lowercase, isogram and right length)
*/
FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid;
	FText Guess = "";
	do {
		std::cout << "Try " << BCGame.GetCurrentTry() << "/" << BCGame.GetMaxTries() << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter isogram, word without repeating letters.\n\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please eneter the word in all lowercase.\n\n";
			break;
		default:
			break;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'Y' || Response[0] == 'y');
}

void PrintGameSummary() {
	if (BCGame.IsGameWon()) std::cout << "Congratulations, you won the game!\n";
	else std::cout << "You lost, better luck next time!\n";
}