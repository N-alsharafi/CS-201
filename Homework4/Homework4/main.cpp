#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include "strutils.h"
//strutils has to be in the solution directory to work with vscode..
using namespace std;
//you might have to copy strutils functions into the program

struct item{
	string QR;
	string name;
	double price;
};

struct shoppingItem {
	string QR;
	int qty;
};

//function declarations:


bool inputProcess(vector<item>& database, const string& input); //processes input lines

item inputSplit(const string& input); //gets the input line and returns an array with item values

bool checkQRCodes(vector<item>& database, const string& QR); //checks unique QRs


//functions for shopping

void shoppingProcess(vector<shoppingItem>& database, vector<item>& inventory);

double itemTotal(vector<item> database, string QR, int quantity);

double VAT(double totalPrice);

double processInfo(vector<shoppingItem>& shoppingList, vector<item>& database);

void printInfo(vector<shoppingItem>& shoppingList, vector<item>& database);


int main() {
	string input;
	vector<item> items;


	cout << "Enter product QR, name, and price (enter 'END' to finish):\n";

	do {
		getline(cin, input);
		bool flag;

		if (input != "END") {
			flag = inputProcess(items, input);
		}

	} while (input != "END"); // POTENTIAL BUG
	cout << endl;

	//now we start the shopping part
	
	vector<shoppingItem> shoppingList;

	cout << "Enter shopping list item QR and quantity (enter END to finish):\n";
	shoppingProcess(shoppingList, items);


	//now we print the final part
	printInfo(shoppingList, items);


	return 0;
}




bool inputProcess(vector<item>& database, const string& input) //processes input lines
{
	item thing;
	thing = inputSplit(input);
	if (checkQRCodes(database, thing.QR)) {
		//the qr is a duplicate
		return false;
	}
	else {
		database.push_back(thing);
		return true;
	}
}

item inputSplit(const string& input) //gets the input line and returns an item struct
{
	item thing;
	int space, dollarSign;

	space = input.find(" ");
	dollarSign = input.find("$"); //POTENTIAL BUG

	string QR;
	double price;

	QR = input.substr(0, space);
	ToUpper(QR); //POTENTIAL BUG

	thing.QR = QR;
	thing.name = input.substr(space + 1, dollarSign -space - 2); //POTENTIAL BUG //Has been fixed
	thing.price = atof(input.substr(dollarSign + 1)); //POTENTIAL ANNOYING BUG //numbers seem to be innaccurate

	return thing;
}

bool checkQRCodes(vector<item>& database, const string& QR) //checks unique QRs
{
	for (int i = 0; i < database.size(); i++) {
		if (database[i].QR == QR) {
			return true;
		}
	}
	return false;
}


void shoppingProcess(vector<shoppingItem>& database, vector<item>& inventory) {
	string shopping;
	do {
		getline(cin, shopping);

		if (shopping != "END") {
			//add the handling of QRs that are not present
			//the handling is added, All I need to do is do something with the bool or turn it into a void
			shoppingItem thing;
			int index, quantity;
			string QR_code;

			index = shopping.find(" ");
			QR_code = shopping.substr(0, index);
			ToUpper(QR_code);
			thing.QR = QR_code;
			quantity = atoi(shopping.substr(index + 1));
			thing.qty = quantity;

			bool availabe = false;
			for (int i = 0; i < inventory.size(); i++) {
				if (inventory[i].QR == thing.QR) {
					availabe = true;
				}
			}

			if (availabe) {
				database.push_back(thing);
			}
			else {

				cout << "Item QR " << thing.QR << " not found in inventory. Please try again.\n";
			}

	
		}
	} while (shopping != "END");
	cout << endl;
	
	//this should work but very questionable

}

double itemTotal(vector<item> database, string QR, int quantity) {
	double itemPrice=0;
	for (int i = 0; i < database.size(); i++) {
		if (database[i].QR == QR) {
			itemPrice = database[i].price * quantity;
		}
	}
	return itemPrice;
}

double VAT(double totalPrice) {
	double VAT;
	VAT = totalPrice * (18.0/100); //POTENTIAL BUG
	return VAT;
}

double processInfo(vector<shoppingItem>& shoppingList, vector<item>& database){
	double totalPrice = 0;
	for (int i = 0; i < shoppingList.size(); i++) {
		double price;
		price = itemTotal(database, shoppingList[i].QR, shoppingList[i].qty);
		totalPrice += price;
	}
	return totalPrice;
}

void printInfo(vector<shoppingItem>& shoppingList, vector<item>& database){
	for (int i = 0; i < shoppingList.size(); i++) {
		for (int j = 0; j < database.size(); j++) {
			if (shoppingList[i].QR == database[j].QR) {
				cout << database[j].name << setw(2) << "*" << setw(4) << shoppingList[i].qty 
					<< setw(31 - database[j].name.size()) << fixed << setprecision(2) //this setpercision is questionable at best
					<< itemTotal(database, shoppingList[i].QR, shoppingList[i].qty)
					<< endl;
			}
		}
		
	}
	double totalPrice = processInfo(shoppingList, database);
	double vat = VAT(totalPrice);
	cout << "\n VAT(18%):" << setw(27) << vat << endl;
	cout << " ____________________________________" << endl;
	cout << " Total:" << setw(30) << totalPrice + vat;

}