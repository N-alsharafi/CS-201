#include <iostream>
#include <string>
#include <vector>
#include "randgen.h"
#include <fstream>
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


void SelectSort(vector<student>& a) {
	// pre: a contains a.size() elements
	// post: elements of a are sorted in non-decreasing order
	int j, k, minIndex, numElts = a.size();
	student temp;
	for (k = 0; k < numElts - 1; k++) {
		minIndex = k;             // minimal element index
		for (j = k + 1; j < numElts; j++)
			if (a[j].ID < a[minIndex].ID)
				minIndex = j;     // new min, store index
		temp = a[k];         // swap min and k-th elements
		a[k] = a[minIndex];
		a[minIndex] = temp;
	}
}


int main() {
	vector<string> names;
	vector<int> IDs;
	string name, lastname, filename;
	RandGen rand;
	ifstream input;

	/*
	do {
		cout << "Enter student name: ";
		cin >> name;
		cout << "Enter student lastname: ";
		cin >> lastname;
		if (name != "END" && lastname != "END") {
			names.push_back(name + " " + lastname);
		}
	} while (name != "END"); //get student names until user enters END
	*/

	cout << "Enter filename: ";
	cin >> filename;
	input.open(filename.c_str());

	if (input.fail()) {
		cout << "Can't find the file...";
	}

	while (getline(input, name)) {
		names.push_back(name);
	}

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
	SelectSort(everything);
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