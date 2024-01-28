#include <iostream>
using namespace std;


void prompt(double& radius, double& cost);
void methamatics(double radius, double cost, double& eff);



int main() {
	double rad1, cos1, eff1, rad2, cos2, eff2;
	prompt(rad1, cos1);
	methamatics(rad1, cos1, eff1);
	prompt(rad2, cos2);
	methamatics(rad2, cos2, eff2);
	if (eff1 > eff2) {
		cout << "pizza 2 is better priced than pizza 1";
	}
	else if (eff1 < eff2) {
		cout << "pizza 1 is better priced than pizza 2";
	}
	else {
		cout << "they are both the same..";
	}



	return 0;
}


void prompt(double& radius, double& cost) {
	cout << "Enter the pizza radius(inch) followed by the cost: ";
	cin >> radius >> cost;
}

void methamatics(double radius, double cost, double& eff) {
	double area = radius * radius * 3.14;
	double sqpincost = cost / area;
	eff = sqpincost;
	cout << "The pizza cost per square inch is " << sqpincost << endl;
}