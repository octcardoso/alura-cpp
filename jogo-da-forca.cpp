#include <iostream>
#include <string>
#include <map>

using namespace std;
string message = "Seja bem vindo ao jogo da forca.";

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

int main() {
	
	initMessage(message);

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


