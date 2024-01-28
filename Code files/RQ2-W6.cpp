#include <iostream>
#include <string>
#include "strutils.h"
using namespace std;

bool dosomething(string input) {
	string puntuation = "?!.,:;/'";
	for (int i = 0; i < input.length(); i++) {
		for (int j = 0; j < puntuation.length(); j++) {
			if (input[i] == puntuation[j]) {
				return true;
			}
		}
	}
	return false;
}




int main() {
	string inp;
	cout << "enter a string: ";
	cin >> inp;
	if (dosomething(inp)) {
		cout << "There is punctuation";
	}
	else {
		cout << "There is no punctuation";
	}
	return 0;
}