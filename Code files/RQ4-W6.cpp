#include <iostream>
using namespace std;

int main() {
	int inp;
	cout << "Enter the number of rows for traingle: ";
	cin >> inp;

	//the up triangle, which should be in a separate function

	for (int i = 0; i < inp; i++) {
		for (int j = inp; j > i; j--) {
			cout << " ";
		}
		for (int j = 0; j < i+1; j++) {
			cout << "*";
		}
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	//the upside down triangle
	//the minus one next to inp is for the diamond question,Q5
	//but then, there also has to be a manipulation operation for the input to make
	//the number of lines consistent with what the question specifies

	for (int i = inp-1; i > 0; i--) {
		for (int j = inp+1; j > i; j--) {
			cout << " ";
		}
		for (int j = 0; j < i ; j++) {
			cout << "*";
		}
		for (int j = 0; j < i-1; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}