#include <iostream>
#include <string>

using namespace std;

bool somethingstupid(string str1, string str2) {
	string first, second;
	first = str1.back();
	second = str2.at(0);
	if (first == second) {
		return true;
	}
	return false;

}


int main() {
	string name1, name2;

	cout << "Enter the 2 names you want to compare: ";
	cin >> name1 >> name2;
	if (somethingstupid(name1, name2)) {
		cout << "Something stupid you wanted is true";
	}
	else {
		cout << "something stupid you wanted is false";
	}



	return 0;
}