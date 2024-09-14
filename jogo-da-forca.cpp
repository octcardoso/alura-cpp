#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute) {
	
	for(char letra : PALAVRA_SECRETA) {
		if(chute == letra) {
			return true;
		}
	}

	return false;
}

bool acertou() {
	for(char letra : PALAVRA_SECRETA) {
		if(!chutou[letra]) {
			return false;
		}
	}
	return true;
}

bool enforcou() {
	return chutes_errados.size() > 4;
}

int main() {
	
	cout << "*****************" << endl;
	cout << "* Jogo da Forca *" << endl;
	cout << "*****************" << endl;
	cout << endl;

	char chute;

	while(!acertou() && !enforcou()) {

		cout << "Chutes errados: ";
		for(char letra : chutes_errados) {
			cout << letra << " ";
		}
		cout << endl;

		for(char letra : PALAVRA_SECRETA) {
			if(chutou[letra]) {
				cout << letra << " ";
			} else {
				cout << "_ ";
			}
		}
		cout << endl;

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
	
	cout << "Fim de jogo!" << endl;
	cout << "A palavra era " << PALAVRA_SECRETA << "." << endl;
	if(acertou()) {
		cout << "Parabéns, você acertou a palavra." << endl;
	} else {
		cout << "Você perdeu, tente novamente." << endl;
	}

	return 0;
}
