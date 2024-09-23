#include <iostream>
#include <map>
#include <vector>
#include "letra_existe.hpp"

std::map<char, bool> chutou;
std::vector<char> chutes_errados;
char chute;

void chuta() {

	std::cout << "Digite o seu chute: ";
	std::cin >> chute;

	chutou[chute] = true;

	if(letra_existe(chute)) {
		std::cout << "Você acertou, a letra " << chute << " está na palavra" << std::endl;
	} else {
		std::cout << "Você errou, a letra " << chute << " não está na palavra" << std::endl;
		chutes_errados.push_back(chute);
	}
	std::cout << std::endl;

}