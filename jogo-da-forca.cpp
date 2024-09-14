#include <iostream>
#include <string>

using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

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
		cout << "Digite o seu chute: ";
		cin >> chute;
		if(letra_existe(chute)) {
			cout << "Você acertou, a letra " << chute << " está na palavra" << endl;
			cout << endl;
		} else {
			cout << "Você errou, a letra " << chute << " não está na palavra" << endl;
			cout << endl;
		}
	}
	
	return 0;
}
