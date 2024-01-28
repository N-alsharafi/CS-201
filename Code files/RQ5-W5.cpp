#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	int index0 = 0; int index1 = 0;
	int sum=0;
	cout << "enter some integers separated by ; ";
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (index1 != string::npos) {
			index1 = input.find(";", index0 + 1);
			sum += stoi(input.substr(index0, index1));
			index0 = index1+1;
		}
		
	}

	cout << sum;
}