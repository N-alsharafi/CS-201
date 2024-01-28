#include <string>
using namespace std;

class Account {	
	public :
		Account(int paramID, string paramOwner); // Constructor of Account Class.
		Account(int paramID);					 // Another constructor of AccountClass.
		void deposit(double amount);			 // deposit some money to this account
		void withdraw(double amount);			 // withdraw some money from this account
		void displayBalance();					 // show how much money is in this account.
		void displayOwner();					 // show owner of this account.
		void transfer(Account& a, double amount); // transfer money from this account to another one.
		
	private:
		string owner;	// name of the owner of the class
		int id;			// unique id of the account
		double balance; // how much is present in the account
};