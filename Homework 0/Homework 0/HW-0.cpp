#include <iostream>
using namespace std;

int main()
{
	double regularLatte;
	int numberOfLattes;
	regularLatte = 51.5;

	cout << "Welcome to the coffee shop!\n";
	cout << "How many lattes would you like to order? ";
	cin >> numberOfLattes;
	cout << "Total price: " << numberOfLattes * regularLatte << " TL";

	return 0;
}