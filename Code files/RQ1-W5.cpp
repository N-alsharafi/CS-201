#include <iostream>
#include <string>
#include "strutils.h"

using namespace std;

string streverse(string base) {
	string reversed, first;
	int ind = 0;
	ind = reversed.rfind(" ");
	first = reversed.substr(ind, reversed.length() - 1);
	return first;

}

int main() {
	string p0, p1, pout = "";
	cout << "Enter 5 string separated by a space: ";
	for (int i = 0; i < 5; i++) {
		p1 += "  ";
		cin >> p0;
		p1 += p0;
		pout.insert(0, p0);
		pout.insert(0, ", "); // there's a tiny problem with the program adding a coma
		//before the first output.
	}
	cout << p1;
	cout << pout;

	return 0;


}