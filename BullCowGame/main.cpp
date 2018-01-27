/* This is console executable, that makes use of BullCow class
This acts as the view in MVC pattern, and is responsible  for all
user interaction. For  game logic see the FBullCowGame class.

*/

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


int main() {

	do {
		printIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}



void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	// TODO change it to while loop depending on get current try
	for (int32 i = 0; i < MaxTries; i++) {
		FText Guess = GetValidGuess();

		// submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//print number bulls and cows

		std::cout << "Bulls = " << BullCowCount.Bulls << ". Cows = " << BullCowCount.Cows << ".\n\n";
	}

	// TODO add game summary
}

void printIntro() {
	//introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl << std::endl;
	return;
}

FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid;
	do {
		FText Guess = "";
		std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter isogram, word without repeating letters.\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please eneter the word in all lowercase.\n";
			break;
		default:
			return Guess;
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'Y' || Response[0] == 'y');
}