#include "Polynomial.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Polynomial p1;
	Polynomial p2;

	cin >> p1;
	cin >> p2;

	pair<Polynomial, Polynomial> p34 = p1.division(p2);

	cout << "������ ���������: " << p1 << endl;
	cout << "������ ���������: " << p2 << endl;
	cout << "�������: " << p34.first << endl;
	cout << "�������: " << p34.second << endl;

	system("pause");

	return 0;
}