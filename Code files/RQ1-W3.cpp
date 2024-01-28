#include <iostream>
using namespace std;

double meth(double cos, int rad) {
	double area, effeciency;
	area = 3.14 * rad * rad;
	effeciency = area / cos;
	return effeciency;
}

int main() {
	double cost1, cost2, pizza1, pizza2;
	int radius1, radius2;
	cout << "Enter the cost followed by the radius for the first pizza: ";
	cin >> cost1 >> radius1;
	cout << "Enter the cost followed by the radius for the second pizza: ";
	cin >> cost2 >> radius2;

	pizza1 = meth(cost1, radius1);
	pizza2 = meth(cost2, radius2);

	if (pizza1 > pizza2) {
		cout << "pizza 1 is more cost efficient";
	} else if (pizza2 > pizza1) {
		cout << "Pizza 2 is more cost efficient";
	}
	else {
		cout << "both pizzas are the same";
	}
	//test case for them being equal

	return 0;

}