#include <iostream>
using namespace std;

int main() // when you run this, you get an error for having multiple main functions,
		   // that's because of the helloworld.cpp
		   // the solution is to right click the file and  exclude from project
{
	int number1, number2, number3, sum;
	
	cout << "Please enter 3 numbers to add up: ";
    cin >> number1 >> number2 >> number3;
	sum = number1 + number2 + number3;
	cout << "the sum is: " << sum << endl; //endline skips a line

    return 0;
}
