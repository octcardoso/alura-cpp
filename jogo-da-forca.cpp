#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;
char chute;

bool letra_existe(char chute) {
	
	for(char letra : palavra_secreta) {
		if(chute == letra) {
			return true;
		}
	}

	return false;
}

bool acertou() {
	for(char letra : palavra_secreta) {
		if(!chutou[letra]) {
			return false;
		}
	}
	return true;
}

bool enforcou() {
	return chutes_errados.size() > 4;
}

void imprime_cabecalho() {

	cout << "*****************" << endl;
	cout << "* Jogo da Forca *" << endl;
	cout << "*****************" << endl;

}

void imprime_erros() {

	cout << "Chutes errados: ";
	for(char letra : chutes_errados) {
		cout << letra << " ";
	}

}

void imprime_palavra() {

	for(char letra : palavra_secreta) {
		if(chutou[letra]) {
			cout << letra << " ";
		} else {
			cout << "_ ";
		}
	}

}

void chuta() {

	cout << "Digite o seu chute: ";
	cin >> chute;

	chutou[chute] = true;

	if(letra_existe(chute)) {
		cout << "Você acertou, a letra " << chute << " está na palavra" << endl;
	} else {
		cout << "Você errou, a letra " << chute << " não está na palavra" << endl;
		chutes_errados.push_back(chute);
	}
	cout << endl;

}

vector<string> le_arquivo() {

	ifstream arquivo;
	arquivo.open("./palavras.txt");
	
	int quantidade_palavras;
	arquivo >> quantidade_palavras;

	vector<string> palavras_do_arquivo;
	
	string palavra_lida;

	for(int i = 0; i < quantidade_palavras; i++) {

		arquivo >> palavra_lida;
		palavras_do_arquivo.push_back(palavra_lida);	

	}

	return palavras_do_arquivo;

}

void sorteia_palavra() {

	vector<string> palavras = le_arquivo();
	srand(time(NULL));
	int indice_aleatorio = rand() % palavras.size();
	palavra_secreta = palavras[indice_aleatorio];

}

int main() {
	
	imprime_cabecalho();
	cout << endl;
	
	sorteia_palavra();
	cout << "A palavra sorteada é " << palavra_secreta << endl;

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
	} else {
		cout << "Você perdeu, tente novamente." << endl;
	}

	return 0;
}
