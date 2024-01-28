#include <iostream>
#include <string>
using namespace std;


bool dosomething(string input) {
	string vowels = "aeiou";
	bool flag1 = false, flag2 = false;
	for (int i = 0; i < input.length()-1; i++) {
		for (int j = 0; j < vowels.length(); j++) { //for checking vowels, it should be a long if statement
			//this gives us a limitation
			if (input[i] == vowels[j]) {
				if (input[i + 1] == vowels[j]) {
					return true; //this does not work
				}
			}
		}
	}
	return false;
}

int main() {
	string inp;
	cout << "Enter some string: ";
	cin >> inp;
	if (dosomething(inp)) {
		cout << "vowel";
	}
	else {
		cout << "no vowel";
	}

	return 0;
}