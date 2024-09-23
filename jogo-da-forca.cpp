#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "imprime_cabecalho.hpp"
#include "sorteia_palavra.hpp"
#include "acertou.hpp"
#include "enforcou.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "adiciona_palavra.hpp"

using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;
char chute;

int main() {
	
	imprime_cabecalho();
	cout << endl;
	
	sorteia_palavra();
	
	while(!acertou() && !enforcou()) {

		imprime_erros();
		cout << endl;

		imprime_palavra();
		cout << endl;
		
		chuta();

	}



	cout << "Fim de jogo!" << endl;
	cout << "A palavra era " << palavra_secreta << "." << endl;
	if(acertou()) {
		cout << "Parabéns, você acertou a palavra." << endl;
        cout << "Você deseja adicionar uma palavra nova ? (S/N)" << endl;
		char resposta;
		cin >> resposta;
		if(resposta == 'S') {
			adiciona_palavra();
		}
	} else {
		cout << "Você perdeu, tente novamente." << endl;
	}

	return 0;
}