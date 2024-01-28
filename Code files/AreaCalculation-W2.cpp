//title: area calculation

/*
This application calculates the area of a circle
*/

#include <iostream>
#include <string>  
//to use string variables
using namespace std;

int main()
{

	string myname;
	int radius;
	double area;

	cout << "Please enter your name: ";
	cin >> myname;
	cout << "Hello, " << myname
		<< " Welcome to my area calculation application!\n";

	cout << "Enter the radius: ";
	cin >> radius;

	//calculate the area
	area = 3.14 * radius * radius;
	cout << "The area of the circle for the radius " << radius
		<< " = " << area;
	return 0;
}