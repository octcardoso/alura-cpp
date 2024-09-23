#include <string>
#include <map>

std::string palavra_secreta;
std::map<char, bool> chutou;

bool acertou() {
	for(char letra : palavra_secreta) {
		if(!chutou[letra]) {
			return false;
		}
	}
	return true;
}