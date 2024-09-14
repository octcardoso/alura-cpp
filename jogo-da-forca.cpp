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

int main() {
	
	bool acertou, enforcou = false;
	char chute;

	while(!acertou && !enforcou) {

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
