#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include "strutils.h"
#include "Products.h"

using namespace std;


float Vat(float total) {
	float vat = total * 0.18;
	return vat;
}

float totalPrice(const vector<Product>& list) {
	float total = 0;
	for (int i = 0; i < list.size(); i++) {
		total += (list[i].amount * list[i].price);
	}

	return total;
}


vector<Product> sortProducts(vector<Product> list) {
	//This function works.
	vector<Product> sorted;
	int index = -1;

	while (list.size() > 0) {
		Product min("", 50, 50, "");
		for (int i = 0; i < list.size(); i++) {
			if ((list[i].price * list[i].amount) < (min.price * min.amount)) {
				min = list[i];
				index = i;
			}
		}
		Product temp = list[list.size() - 1];
		list[index] = temp;
		list.pop_back();
		sorted.push_back(min);
	}

	//the part where we sort similar elements according to name.
	for (int i = 0; i < sorted.size()-1; i++) {
		if ((sorted[i].price * sorted[i].amount) == (sorted[i + 1].price * sorted[i + 1].amount)) {
			if (sorted[i].name > sorted[i + 1].name) {
				Product temp("", -1, -1, "");
				temp = sorted[i];
				sorted[i] = sorted[i + 1];
				sorted[i + 1] = temp;
			}
		}
	}

	return sorted;
}


vector<Product> reverse(const vector<Product>& list) {
	vector<Product> reversed;
	for (int i = list.size() - 1; i >= 0; i--) {
		reversed.push_back(list[i]);
	}
	return reversed;
}

Products::Products() {}
Products::Products(const Products& p) {}


vector<Product> Products::get_item_list() const {
	return item_list;
}

vector<Product> Products::get_shop_list() const {
	return shop_list;
}

void Products::read_files(ifstream& qr, ifstream& price) {

	string line;
	while (getline(qr, line)) {
		string code, name, temp;
		int index = 0;
		istringstream strStream(line);
		while(strStream >> temp) {
			if (index == 0) {
				code = temp;
				
			}
			else if (index == 1) {
				name = temp;
			}
			else {
				name = name + " " + temp;
			} //this should work; it does work

			index++;
		}
		Product p(name, -1, -1, code);
		item_list.push_back(p);
	}


	while (getline(price, line)) {
		string code, temp;
		float price=-1;
		int index = 0;
		istringstream strStream(line);
		while (strStream >> temp) {
			if (index == 0) {
				code = temp;
			}
			else {
				price = stof(temp);
			}
			index++;
		}
		Product p("", -1, price, code);
		for (int x = 0; x < item_list.size(); x++) {
			if (item_list[x].qr_code == p.qr_code) {
				item_list[x].price = p.price;
			}
		}
	}
}

bool Products::find(string qr_code) {
	bool flag = false;

	for (int i = 0; i < item_list.size(); i++) {
		if (item_list[i].qr_code == qr_code) {
			flag = true;
		}
	}
	return flag;
}

bool Products::findInShopList(string qr_code) {
	bool flag = false;

	for (int i = 0; i < shop_list.size(); i++) {
		if (qr_code == shop_list[i].qr_code) {
			flag = true;
		}
	}
	return flag;
}

void Products::add_item(string qr, int amount) {
	Product s("", -1, -1, "");
	for (int i = 0; i < item_list.size(); i++) {
		if (item_list[i].qr_code == qr) {
			s = item_list[i];
			s.amount = amount;
		}
	}
	string temp = "";
	if (s.qr_code != temp) {
		shop_list.push_back(s);
	}
	else {
		cout << "Error in add_item function, product not found";
		//maybe this part can contain the error not found part
		//of the requirements
	}
}

void Products::edit_item(string qr, int amount) {
	for (int i = 0; i < shop_list.size(); i++) {
		if (qr == shop_list[i].qr_code) {
			shop_list[i].amount = amount;
		}
	}
}

void Products::remove_item(string qr) {
	int indexToPop = -1;
	for (int i = 0; i < shop_list.size(); i++) {
		if (shop_list[i].qr_code == qr) {
			indexToPop = i;
		}
	}
	for (int j = indexToPop; j < shop_list.size(); j++) {
		if (j == shop_list.size() - 1) {

		}
		else {
			shop_list[j] = shop_list[j + 1];
		}
	} //this probably works now
	shop_list.pop_back();

}

void Products::printCurrentReceipt() {
	for (int i = 0; i < shop_list.size(); i++) {
		cout << setw(5) << shop_list[i].name << " * " << setw(3) << shop_list[i].amount
			<< setw(31 - shop_list[i].name.size()) << fixed <<
			setprecision(1) << shop_list[i].price * shop_list[i].amount << endl;
	}

	float total = totalPrice(shop_list);
	float vat = Vat(total);

	cout << "\nVAT(18%):" << setw(28) << vat << endl;
	cout << "_______________________________________" << endl;
	cout << "Total:" << setw(31) << (total + vat) << endl << endl;

	//this should work, however the formatting can get annoying
}

void Products::printCurrentReceiptAscending() {
	vector<Product> a = sortProducts(shop_list);

	for (int i = 0; i < a.size(); i++) {
		cout << setw(5) << a[i].name << " * " << setw(3) << a[i].amount
			<< setw(31 - a[i].name.size()) << fixed <<
			setprecision(1) << a[i].price * a[i].amount << endl;
	}

	float total = totalPrice(shop_list);
	float vat = Vat(total);

	cout << "\nVAT(18%):" << setw(28) << vat << endl;
	cout << "_______________________________________" << endl;
	cout << "Total:" << setw(31) << (total + vat) << endl << endl;

	
}

void Products::printCurrentReceiptDescending() {
	vector<Product> a = sortProducts(shop_list);
	a = reverse(a);

	for (int i = 0; i < a.size(); i++) {
		cout << setw(5) << a[i].name << " * " << setw(3) << a[i].amount
			<< setw(31 - a[i].name.size()) << fixed <<
			setprecision(1) << a[i].price * a[i].amount << endl;
	}

	float total = totalPrice(shop_list);
	float vat = Vat(total);

	cout << "\nVAT(18%):" << setw(28) << vat << endl;
	cout << "_______________________________________" << endl;
	cout << "Total:" << setw(31) << (total + vat) << endl << endl;
}