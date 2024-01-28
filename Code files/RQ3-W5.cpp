#include <iostream>
#include <string>

using namespace std;

int digits(int whaaat) {
	return to_string(whaaat).length();
}

int main() {
	int input;
	cout << "enter an integer with lots of digits; ";
	cin >> input;
	cout << digits(input);

	return 0;
}