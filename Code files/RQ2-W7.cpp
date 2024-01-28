#include <iostream>
#include <vector>
using namespace std;


int max(const vector <int> input) {
	int max = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] > max) {
			max = input[i];
		}
	}
	return max;
}

bool sorted(const vector <int> input) {
	for (int i = 0; i < input.size() - 1; i++) {
		if (input[i + 1] < input[i]) {
			return false;
		}
	}
	return true;
}

void dosomething(vector <int>& input, int value, int location) {
	//pre: location is in the range of the vector
	input[location] = value;
	//the way we were supposed to do this function is to add the value and shift 
	//all the later values, so we lose the last one
}

void undosomething(vector <int>& input, int location) {
	//pre: location is in the ragne of the vector
	input[location] = 0;
}


int main() {
	//this code has not been tested, but trust me it works
	int n;
	cout << "Enter the size of the vector: ";
	cin >> n;
	vector <int> idk(n, 0);

}