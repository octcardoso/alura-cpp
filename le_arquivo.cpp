#include <iostream>
#include <fstream>
#include "le_arquivo.hpp"

std::vector<std::string> le_arquivo() {

	std::ifstream arquivo;
	arquivo.open("./palavras.txt");
	
	if(!arquivo.is_open()) {
		std::cout << "Não foi possível acessar o banco de palavras" << std::endl;
		exit(0);
	}

	int quantidade_palavras;
	arquivo >> quantidade_palavras;

	std::vector<std::string> palavras_do_arquivo;
	
	std::string palavra_lida;

	for(int i = 0; i < quantidade_palavras; i++) {

		arquivo >> palavra_lida;
		palavras_do_arquivo.push_back(palavra_lida);	

	}
	
	arquivo.close();
	return palavras_do_arquivo;

}