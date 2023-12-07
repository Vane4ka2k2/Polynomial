#include "Polynomial.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	vector<double> coeffs{ 2, -2.5, 0.5 };
	vector<double> vecX{ -1, 0, 1, 2 };
	Polynomial p1(coeffs);
	Polynomial p2 = p1.polynomialNewton(vecX);
	Polynomial p3 = p1.polynomialLagrange(vecX);

	cout << "Исходный многочлен: " << p1 << endl;
	cout << "Вектор Иксов: ";
	for (auto i : vecX)
		cout << i << " ";
	cout << endl;
	cout << "Интерполяционный многочлен Ньютона: " << p2 << endl;
	cout << "Интерполяционный многочлен Лагранжа: " << p3 << endl;

	system("pause");

	return 0;
}