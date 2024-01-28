#include <iostream>
#include <string>
#include <vector>
using namespace std;

int glob = 0;

void printArray(const int[], int, string);
void printVector(const vector<int>, string);

void func3(int intarr[], int SIZE) {
	glob++;
	for (int i = 0; i < SIZE; i++)
		intarr[i] ++;
	printArray(intarr, SIZE, "In func3, array: ");
}
void func2(vector<int> intvec) {
	static int stat = 1;
	for (int i = 0; i < intvec.size(); i++)
		intvec[i]++;
	printVector(intvec, "In func2, vector: ");
	stat++;
	glob++;
	cout << "In func2, static int: " << stat << endl;
}
void func1(vector<int>& intvec) {
	glob++;
	for (int i = 0; i < intvec.size(); i++)
		intvec[i] ++;
	printVector(intvec, "In func1, vector: ");
	func2(intvec);
}
int main() {
	const int SIZE = 3;
	vector <int> intvec;
	int intarr[SIZE];
	for (int i = 0; i < 6; i = i + 2) {
		intvec.push_back(i);
		intarr[i / 2] = i;
	}
	printVector(intvec, "Before func1, vector: ");
	printArray(intarr, SIZE, "Before func1, array: ");
	cout << "Before func1, global int: " << glob << endl;
	func1(intvec);
	printVector(intvec, "After func1, vector: ");
	cout << "After func1, global int: " << glob << endl;
	func2(intvec);
	printVector(intvec, "After func2, vector: ");
	cout << "After func2, global int: " << glob << endl;
	func3(intarr, SIZE);
	printArray(intarr, SIZE, "After func3, array: ");
	cout << "After func3, global int: " << glob << endl;
	return 0;
}
void printArray(const int intarr[], int SIZE, string message) {
	cout << message;
	for (int i = 0; i < SIZE; i++)
		cout << intarr[i] << " ";
	cout << endl;
}

void printVector(const vector<int> intvec, string message) {
	cout << message;
	for (int i = 0; i < intvec.size(); i++)
		cout << intvec[i] << " ";
	cout << endl;
}
