#include <iostream>
#include <math.h>
// pow(num, power)
//sqrt(num)
using namespace std;



double average(int num1, int num2) {
	int totalSum=0; double average;
	totalSum = num1 + num2;
	average = double(totalSum) / 2;
	return average;

}


double standardDeviation(int num1, int num2, double average) {
	int count = num2 - num1 + 1;
	double sum = 0;
	double stdDev;

	for (int i = num1; i <= num2; i++) {
		sum += pow(i - average, 2);
	}
	stdDev = sqrt(sum / count);
	return stdDev;
}

int main() {
	int num1, num2;
	cout << "enter the two numbers separated by space: ";
	cin >> num1 >> num2;
	cout << "the average is " << average(num1, num2);
	//output standard deviation line is not here..d
	return 0;
}