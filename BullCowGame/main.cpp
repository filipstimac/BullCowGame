#include<iostream>
#include<string>
#include "FBullCowGame.h"

void printIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();



int main() {

	do {
		printIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}



void PlayGame() {
	FBullCowGame BCGame;
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 0; i < NUMBER_OF_TURNS; i++) {
		std::cout << "Your guess was: " << GetGuess() << std::endl;
		std::cout << std::endl;
	}
}

void printIntro() {
	//introduce the game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl << std::endl;
	return;
}

std::string GetGuess() {
	std::string Guess = "";
	std::cout << "Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'Y' || Response[0] == 'y');
}