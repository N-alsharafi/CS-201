#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include "strutils.h"

using namespace std;

struct Product {
    string name, qr_code;
    int amount;
    float price;
    Product() {}; 
    Product(string n = "", int a = -1, float p = -1, string qr = "") :name(n), amount(a), price(p), qr_code(qr) {};
};


class Products {

private:
    vector<Product> item_list;
    vector<Product> shop_list;

public:
    Products();
    Products(const Products& p);
    //accessor (getter) functions
    vector<Product> get_item_list() const;
    vector<Product> get_shop_list() const;


    // you are going to implement these member functions
    void read_files(ifstream& qr, ifstream& price);
    // it reads qr and price files and stores them into item_list

    bool find(string qr_code);
    // given qr code it searches that inside item_list

    bool findInShopList(string qr_code);
    // given qr code it searches that inside shop_list

    void add_item(string qr, int amount);
    // adds an item to the shop_list

    void edit_item(string qr, int amount);
    // edits an item in the shop_list

    void remove_item(string qr);
    // removes an item from the shop_list

    void printCurrentReceipt();
    // prints the current receipt

    void printCurrentReceiptAscending();
    // prints the current receipt in ascending order with respect to total prices

    void printCurrentReceiptDescending();
    // prints the current receipt in descending order with respect to total prices

};
