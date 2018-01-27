#include<iostream>
#include<string>
#include "FBullCowGame.h"

void printIntro();
void PlayGame();
std::string GetGuess();
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
	int MaxTries = BCGame.GetMaxTries();

	// TODO change it to while loop depending on get current try
	for (int i = 0; i < MaxTries; i++) {
		std::cout << "Your guess was: " << GetGuess() << std::endl; // TODO check if guess is valid word

		// submit valid guess to the game
		//print number bulls and cows

		std::cout << std::endl;
	}

	// TODO add game summary
}

void printIntro() {
	//introduce the game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl << std::endl;
	return;
}

std::string GetGuess() {
	std::string Guess = "";
	std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'Y' || Response[0] == 'y');
}