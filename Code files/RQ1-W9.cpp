#include <iostream>
#include <string>
#include <vector>
#include "randgen.h"
using namespace std;

struct student {
	string name;
	int ID;
};


bool uniqueID(vector<int> IDs, int ID) {
	bool flag = true;
	for (int i = 0; i < IDs.size(); i++) {
		if (ID == IDs[i]) {
			flag = false;
		}
	}
	return flag;
}


vector<student> uselessfunction(const vector<string>& names, const vector<int>& IDs) {
	vector<student> list;
	for (int i = 0; i < names.size(); i++) {
		student stu;
		stu.name = names[i];
		stu.ID = IDs[i];
		list.push_back(stu);
	}
	return list;
}

void print(const vector<student>& everything) {
	for (int i = 0; i < everything.size(); i++) {
		cout << everything[i].name << " " << everything[i].ID << endl;
	}

}

string requested(const vector<student>& everything, int id) {
	for (int i = 0; i < everything.size(); i++) {
		if (everything[i].ID == id) {
			return everything[i].name;
		}
	}
	return "name not found";
}

int main() {
	vector<string> names;
	vector<int> IDs;
	string name, lastname;
	RandGen rand;

	do {
		cout << "Enter student name: ";
		cin >> name;
		cout << "Enter student lastname: ";
		cin >> lastname;
		if (name != "END" && lastname != "END") {
			names.push_back(name+ " " +lastname);
		}
	} while (name != "END"); //get student names until user enters END

	int counter = 0;
	while (counter < names.size()) {
		bool flag = true;
		while (flag) {
			int Id = rand.RandInt(10000, 99999);
			if (uniqueID(IDs, Id)) {
				IDs.push_back(Id);
				flag = false;
			}
		}
		counter++;
	}

	vector<student> everything = uselessfunction(names, IDs);
	print(everything);

	//this is where the user asks for a specific ID
	int requestedId;
	string requestedName;
	do {
		cout << "Enter a student ID and I will return the student name (-1 to close): ";
		cin >> requestedId;
		if (requestedId != -1) {
			requestedName = requested(everything, requestedId);
		}
		cout << requestedName << " is the name bound to the ID: " << requestedId << endl;
	} while (requestedId != -1);

	return 0;
}