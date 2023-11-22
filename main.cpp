#include "Polynomial.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	vector<double> coeffs{ 2, -5 / 2, 0, 0.5 };
	vector<double> vecX{ -1, 0, 1, 2 };
	Polynomial p1(coeffs);
	Polynomial p2 = p1.methodLagrange(vecX);

	cout << "�������� ���������: " << p1 << endl;
	cout << "������ �����: ";
	for (auto i : vecX)
		cout << i << " ";
	cout << endl;
	cout << "���������������� ��������� ��������: " << p2 << endl;

	system("pause");

	return 0;
}