#include <iostream>
#include <string>
#include <map>

using namespace std;
string message = "Seja bem vindo ao jogo da forca.";
string secretWord = "MELANCIA";
map<char, bool> attempedLetters;
char guess;

void initMessage(string welcomeMessage) {
	
	string header;
	welcomeMessage = "* " + welcomeMessage + " *";
	for(char letter : welcomeMessage) {
		header += "*";
	}
	
	cout << header << endl;
	cout << welcomeMessage << endl;
	cout << header << endl;

}

bool guessedLetter(char guess) {
	
	for(char letter : secretWord) {
		
		if(letter == guess) {
	
			attempedLetters[guess] = true;
			return true;
	
		}
	
	}
	
	attempedLetters[guess] = false;
	return false;	

}

void printWord() {
	
	for(char letter : secretWord) {
		
		if(attempedLetters[letter]) {

			cout << letter << " ";

		} else {

			cout << "_ ";

		}
		
	}

}

int main() {
	
	bool alive = true;
	
	initMessage(message);
	cout << endl << secretWord << endl;
	printWord();
	cout << endl;
	cout << "A palavra tem " << secretWord.length() << " letras." << endl;
	cout << "Boa sorte." << endl;

	while(alive) {
		
		cout << "Insira o seu chute: ";
		cin >> guess;
		cout << endl;

		if(guessedLetter(guess)) {
			cout << "Você acertou, a letra " << guess << " está dentro da palavra" << endl;
			printWord();
			cout << endl;
		} else {
			cout << "Você errou, a letra " << guess << " não está dentro da palavra" << endl;
			printWord();
			cout << endl;
		}
		

		
	}

	return 0;

}



/*
	 * 
	 *
	 * bem vindo ao jogo da forca
	 * aperte 0 para iniciar e 2 para sair
	 * 0. iniciar
	 * 1. sair
	 *
	 * randomiza uma palavra
	 * imprime _ da palavra
	 * começa os chutes
	 * para cada chute errado vai perdendo vida...
	 *
	 * */	


