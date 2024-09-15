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
	
	if(!arquivo.is_open()) {
		cout << "Não foi possível acessar o banco de palavras" << endl;
		exit(0);
	}

	int quantidade_palavras;
	arquivo >> quantidade_palavras;

	vector<string> palavras_do_arquivo;
	
	string palavra_lida;

	for(int i = 0; i < quantidade_palavras; i++) {

		arquivo >> palavra_lida;
		palavras_do_arquivo.push_back(palavra_lida);	

	}
	
	arquivo.close();
	return palavras_do_arquivo;

}

void sorteia_palavra() {

	vector<string> palavras = le_arquivo();
	srand(time(NULL));
	int indice_aleatorio = rand() % palavras.size();
	palavra_secreta = palavras[indice_aleatorio];

}

void salva_arquivo(vector<string> nova_lista) {

	ofstream arquivo;
	arquivo.open("./palavras.txt");
	if(!arquivo.is_open()) {
		cout << "Falha ao salvar o arquivo." << endl;
		exit(0);
	}
	
	arquivo << nova_lista.size() << endl;
	for(string palavra : nova_lista) {
		arquivo << palavra << endl;
	}
	
	cout << "Sua palavra foi salva! Obrigado por contribuir com o jogo!" << endl;
	arquivo.close();

}

void adiciona_palavra() {
	
	cout << "Digite a nova palavra usando letras maiusculas: " << endl;
	string nova_palavra;
	cin >> nova_palavra;
	
	vector<string> lista_palavras = le_arquivo();
	lista_palavras.push_back(nova_palavra);

	salva_arquivo(lista_palavras);

}

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
