/*
Account class that handles bank account operations.
*/

#include<iostream>
#include "account.h"
using namespace std;

Account::Account(int paramID, string paramOwner){
	id = paramID;
	owner = paramOwner;
	balance = 0;
}

Account::Account(int paramID){
	id = paramID;
	owner = "anonymous";
	balance = 0;
}

void Account::deposit(double amount){	
	if (amount <= 0) 
		cout << "Deposit amount could not be less than or equal to zero" << endl;
	else
		balance += amount;
}

void Account::withdraw(double amount){
	if (amount <= 0) 
		cout << "Withdraw amount could not be less than or equal to zero" << endl;
	else{
		if (amount <= balance) 	
			balance -= amount;
		else
			cout << "There is not enough money to be withdrawn" << endl;
	}
}

void Account::displayBalance(){	
	cout << "Account " << id << " has " << balance << " amount of money" << endl;
}

void Account::displayOwner(){	
	cout << "Account " << id << " belongs to " << owner << endl;
}

void Account::transfer(Account& a, double amount){
	if (amount <= 0)
		cout << "Transfer amount could not be less than or equal to zero" << endl;
	else{
		if (balance < amount){
			cout << "WARNING: Not enough money in account " << id << endl;
		}
		else{
			cout << "MESSAGE: Transfer completed" << endl;
			withdraw(amount);
			a.deposit(amount);
		}
	}
}