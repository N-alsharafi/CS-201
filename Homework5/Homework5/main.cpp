#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include"Products.h"
#include"strutils.h"

using namespace std;

void option1(Products& market);
void option2(Products& market);
void option3(Products& market);
void option4(Products& market);
void option5(Products& market);
void option6(Products& market);


void printmenu() {
	cout << "MENU\n";
	cout << "1. Add item to the shopping list\n";
	cout << "2. Delete item from the shopping list\n";
	cout << "3. Edit the amount of existing item\n";
	cout << "4. Print current receipt\n";
	cout << "5. Print current receipt in order\n";
	cout << "6. Print current receipt in reverse order\n";
	cout << "7. Exit\n";
	cout << "---\n";
}



int main() {
	
	string qrdatabase = "";
	ifstream input;

	cout << "Please enter a filename for QR database: ";
	cin >> qrdatabase;
	input.open(qrdatabase.c_str());

	while (input.fail()) {
		cout << "\nThe QR file does not exists\n";
		cout << "Please enter a filename for QR database: ";
		cin >> qrdatabase;

		input.open(qrdatabase.c_str());

	}

	cout << endl;

	string pricedb;
	ifstream priceinput;

	cout << "Please enter a filename for Price database: ";
	cin >> pricedb;
	priceinput.open(pricedb.c_str());

	while (priceinput.fail()) {
		cout << "\nThe Price file does not exists\n";
		cout << "Please enter a filename for Price database: ";
		cin >> pricedb;

		priceinput.open(pricedb.c_str());

	}

	Products market;
	market.read_files(input, priceinput);



	while (true) {
		printmenu();
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) { option1(market); }
		else if (choice == 2) { option2(market); }
		else if (choice == 3) { option3(market); }
		else if (choice == 4) { option4(market); }
		else if (choice == 5) { option5(market); }
		else if (choice == 6) { option6(market); }
		else if (choice == 7) { 
			cout << "Goodbye!";
			return 0; 
		}
	}
	
	return 0;
}


void option1(Products& market)// keep in mind maximum amount is 25
{
	string qr;
	int amount;
	cout << "Please enter the QR code to add: ";
	cin >> qr;
	ToUpper(qr);
	if (market.find(qr)) {
		if (market.findInShopList(qr)) {
			cout << "Item is already in the shoplist, if you want to edit the amount please choose option 3\n";
		}
		else {
			cout << "Please enter the amount to add: ";
			cin >> amount;

			if (amount < 1 || amount >25) {
				cout << "Invalid amount, try again\n";
			}
			else {
				market.add_item(qr, amount);
			}
		}
		
	}
	else {
		cout << "Invalid QR code, try again\n";
	}
	
}
void option2(Products& market) {
	string qr;
	cout << "Please enter the QR code to delete: ";
	cin >> qr;

	if (market.findInShopList(qr)) {
		market.remove_item(qr);
	}
	else {
		cout << "Shoplist does not contain the given QR code.\n";
	}
	//there might be logic errors inside these implementations;
}
void option3(Products& market)// keep in mind maximum amount is 25
{
	string qr;
	cout << "Please enter the QR code to edit: ";
	cin >> qr;
	ToUpper(qr);
	
	if (market.find(qr) && market.findInShopList(qr)) {
		int newamount;
		cout << "Please enter the amount to edit: ";
		cin >> newamount;
		if (newamount < 1 || newamount > 25) {
			cout << "Invalid amount, try again\n";
		}
		else {
			market.edit_item(qr, newamount);
		}
	}
	else {
		cout << "Invalid QR code, try again\n";
	}

}
void option4(Products& market) { market.printCurrentReceipt(); }
void option5(Products& market) { market.printCurrentReceiptAscending(); }
void option6(Products& market) { market.printCurrentReceiptDescending(); }