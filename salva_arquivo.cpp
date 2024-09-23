#include <vector>
#include <string>
#include <fstream>
#include <iostream>

void salva_arquivo(std::vector<std::string> nova_lista) {

	std::ofstream arquivo;
	arquivo.open("./palavras.txt");
	if(!arquivo.is_open()) {
		std::cout << "Falha ao salvar o arquivo." << std::endl;
		exit(0);
	}
	
	arquivo << nova_lista.size() << std::endl;
	for(std::string palavra : nova_lista) {
		arquivo << palavra << std::endl;
	}
	
	std::cout << "Sua palavra foi salva! Obrigado por contribuir com o jogo!" << std::endl;
	arquivo.close();

}