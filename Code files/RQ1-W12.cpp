#include <iostream>
#include<string>
#include "account.h"
using namespace std;

int main() {
	Account n1(123, "Mazhar");
	Account n2(124, "Fuat");
	Account n3(125, "Ozkan");

	Account n4(126);

	n1.displayOwner();
	
	n2.displayOwner();
	
	n3.displayOwner();
	
	n4.displayOwner();

	cout << "All owners have been displayed.." << endl;

	//-------------

	n1.deposit(100);
	n2.deposit(150);
	n3.deposit(1000);

	n1.displayBalance();
	n2.displayBalance();
	n3.displayBalance();
	cout << "Balances have been displayed\n";

	n1.transfer(n2, 25); //these transfers should be in functions
	n1.displayBalance();
	n2.displayBalance();

	n1.transfer(n3, 45);
	n1.displayBalance();
	n3.displayBalance();

	n3.transfer(n2, 50);
	n3.displayBalance();
	n2.displayBalance();

	n4.withdraw(100);

	return 0;
}