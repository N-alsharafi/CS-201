
#include <iostream>
using namespace std;

int main() {
	float weight, height, BMI;

	cout << "Please enter your weight in KGs: ";
	cin >> weight;
	cout << "Please enter your height in metres (6ft is 1.82m): ";
	cin >> height;

	BMI = weight / (height * height);
	cout << "Your BMI based on the inputs you provided is: " << BMI << endl;
	if (BMI > 24.9) {
		cout << "You're FAT.";
	}
	else if ( BMI <= 24.9 && BMI >= 18.5) {
		cout << "You're very average, take is as an insult.";
	}
	else {
		cout << "You're so thin, the government will only issue you half an identity card.";
	}

	return 0;
}