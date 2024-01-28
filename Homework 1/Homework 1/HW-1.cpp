#include <iostream>
#include<string>
using namespace std;

//create an input function that vets everything and returns the variables
//create a calculation function that does all the math and return all the variables
//create a void function that prints the report

int main() {


	//defining variables

	string companyName;
	double grossIncome, expenses, vat, profit, corporateTax, netProfit, dividend, capitalIncrease;
	int noOfShareholders;
	capitalIncrease = dividend = 0;


	//getting and vetting inputs

	cout << "This accounting program calculates the state taxes and dividends "
		<<"for the company shareholders." << endl;
	cout << "Please enter the name of the company: ";
	cin >> companyName;

	cout << "Please enter the gross income of " << companyName << ": ";
	cin >> grossIncome;

	if (grossIncome <= 0) {
		cout << "Invalid input for gross income (Gross Income must be greater than 0).\n"
			<< "Stopping calculations...";
		return 0;
	}


	cout << "Please enter expenses of " << companyName << ": ";
	cin >> expenses;

	if (expenses < 0) {
		cout << "Invalid input for expenses (Expenses must be greater than or equal 0).\n"
			<< "Stopping calculations...";
		return 0;
	}


	cout << "Please enter the number of shareholders: ";
	cin >> noOfShareholders;

	if (noOfShareholders < 1) {
		cout << "Invalid input for number of shareholders (Number of shareholders must"
			<< " be greater than or equal to 1).\n" << "Stopping calculations...";
		return 0;
	}


	//doing calculations

	vat = grossIncome * 0.18;

	profit = grossIncome - vat - expenses;

	if (profit <= 0) {
		corporateTax = 0;
	}
	else if (profit <= 10000) {
		corporateTax = 0.10;
	}
	else if (profit <= 25000) {
		corporateTax = 0.15;
	}
	else if (profit <= 50000) {
		corporateTax = 0.20;
	}
	else if (profit > 50000) {
		corporateTax = 0.25;
	}

	netProfit = profit - (profit * corporateTax);
	
	if (netProfit == 0) {
		dividend = capitalIncrease = 0;
	}
	else if (netProfit > 0) {
		dividend = capitalIncrease = netProfit * 0.5;
		dividend /= noOfShareholders;
		dividend *= (1 - 0.15); //final dividend is not stored in dividend
	}

	//printing the financial report

	cout << endl << "*********** " << companyName << " Financial Report **********" << endl << endl ;
	if (netProfit == 0) {
		cout << "Net Profit: " << netProfit << " TL. (Break Even)\n";
	}
	else if (netProfit < 0) {
		cout << "Net Loss: " << netProfit << " TL.\n";
	}
	else {
		cout << "Net Profit: " << netProfit << " TL.\n";
	}
	cout << "VAT: " << vat << " TL.\n";
	cout << "Corporate Tax: " << abs(profit) * corporateTax << " TL.\n" << endl;
	
	cout << "Capital Increase: " << capitalIncrease << " TL.\n";
	cout << noOfShareholders << " shareholders will have a share of: " << dividend << " TL.\n";
	

	return 0;
}