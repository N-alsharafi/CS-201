#include <iostream>
#include <vector>
#include "randgen.h"
using namespace std;


int main() {
	int n,k=0, num;
	RandGen rand;
	cout << "Enter a number: ";
	cin >> n;
	vector <int> occurences(n, 0);
	while (k < 1000) {
		num =  rand.RandInt(n);
		occurences[num] +=1;
		k++;
	}

	for (int i = 0; i < occurences.size(); i++) {
		cout << occurences[i] << endl;
	}

	return 0;
}