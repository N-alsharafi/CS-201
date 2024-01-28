#include <iostream>
#include <string>
using namespace std;

void printing(string name, string lastname, int day, int month, int year, int duedate, int duemonth,
	int dueyear, double amount, double interest);

bool inputchecks(double amount, int day, int month, int year);

int dueMonthYear(int month, int& year);

int main() {
	string name, lastName;
	int day, month, year;
	int dueDate, dueMonth, dueYear;
	double amount, interest;

	//getting the inputs
	cout << "Enter name followed by last name separated by a space: ";
	cin >> name >> lastName;
	cout << "Enter the date today (Day Month Year) separated by a space: ";
	cin >> day >> month >> year;
	cout << "Enter the amount the user owes followed by the interest the user has to pay: ";
	cin >> amount >> interest;

	//input checks
	if (inputchecks(amount, day, month, year)) {
		cout << "a valule you entered is incorrect, program shutting down...";
		return 0;
	}

	//calculating new dates
	dueDate = day;
	dueYear = year;
	dueMonth = dueMonthYear(month, dueYear); //this updates both month and year

	//printing the report
	printing(name, lastName, day, month, year, dueDate, dueMonth, dueYear, amount, interest);

	return 0;
}


int dueMonthYear(int month, int& year) {
	if (month % 12 == 0) {
		year++;
		month = 1;
	}
	else {
		month++;
	}
	return month;
}


void printing(string name, string lastname, int day, int month, int year, int duedate, int duemonth,
	int dueyear, double amount, double interest) {
	cout << "\n                                           " << day << "/" << month << "/" << year << endl;
	cout << endl << "Dear " << name << " " << lastname << ":" << endl << endl;
	cout << "Our records show a balance of $" << amount << " as of " << day << "/" << month << "/" << year<<"."<<endl;
	cout << "In order to avoid any late penalty please pay your bill in full \nuntil " << duedate << "/"
		<< duemonth << "/" << dueyear << ".";
	cout << "Otherwise we will have to charge a late penalty (monthly " << interest*100 << "%) as \nshown bellow." << 
		endl << endl;
	cout << "30 days past due, you pay $" << amount * (1 + interest);
	cout << "\n60 days past due, you pay $" << amount * (1 + (2 * interest));
	cout << "\n90 days past due, you pay $" << amount * (1 + (3 * interest)) << endl << endl;
	cout << "Best regards, " << endl << endl;
	cout << "CS201 corporation";
}


bool inputchecks(double amount, int day, int month, int year) {
	if (amount >= 0 && day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 0) {
		if (month == 2 && day > 29) {
			return true;
		}
		return false;
	}
	return true;
}