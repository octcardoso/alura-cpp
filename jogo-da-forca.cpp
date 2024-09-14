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

bool nao_acertou() {
	for(char letra : PALAVRA_SECRETA) {
		if(!chutou[letra]) {
			return true;
		}
	}
	return false;
}

bool nao_enforcou() {
	return chutes_errados.size() <= 6;
}

int main() {
	
	cout << "*****************" << endl;
	cout << "* Jogo da Forca *" << endl;
	cout << "*****************" << endl;
	cout << endl;

	char chute;

	while(nao_acertou() && nao_enforcou()) {

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
	}
	
	return 0;
}
