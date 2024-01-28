#include <iostream>
#include <string>

using namespace std;

int smileys(string str) {
	int smileys = 0;

	for (int i = 0; i < str.length()-1; i++) {
		if (str[i] == ':' && str[i + 1] == ')') {
			smileys++;
		}
	}
	return smileys;
}

int main() {
	string input;
	cout << "Enter text: ";
	cin >> input;
	cout << smileys(input);

	return 0;
}
