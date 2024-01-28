#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
	for (int i = 0; i < s.length(); i++) {

		if (s.at(i) != s.at(s.length() - i - 1)) {
			return false;
		}
	}
	return true;
}


int countPanlindrome(string s) {
	string substring;
	unsigned int count = 0; //you can define it as unsigned because it will never be
	//negative for us
	for (int i = 0; i < s.length(); i++) {
		for (int j = 2; j <= s.length() - i; j++) {
			substring = s.substr(i, j);
			if (isPalindrome(substring)) {
				count += 1;
				cout << substring << " is a palindrome";
			}
		}
	}
	return count;

}


int main() {

	return 0;
}