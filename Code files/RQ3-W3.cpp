#include <iostream>
using namespace std;

double salarymath(double salary) {
	if (salary > 0 && salary <= 1000) {
		salary += salary * 0.15;
	}
	else if (salary <= 2000) {
		salary += salary*0.10;
	}
	else if (salary <= 3000) {
		salary += salary * 0.05;
	}
	else if (salary > 3000) {
		salary += salary * 0.025;
	}
	else {
		cout << "what the fuck did you write, the program broke";
	}
	return salary;
}


int main() {
	double usrsalary;
	cout << "Enter your salary: ";
	cin >> usrsalary;

	cout << "your new salary is " << salarymath(usrsalary);
	return 0;
}