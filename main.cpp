#include "Polynomial.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	/*vector<double> coeffs{ -2, -5, 0, -4 };
	vector<double> vecX{ 0, 1, 2, 3 };
	Polynomial p1(coeffs);
	Polynomial p2 = p1.polynomialLagrange(vecX);

	cout << "Исходный многочлен: " << p1 << endl;
	cout << "Вектор Иксов: ";
	for (auto i : vecX)
		cout << i << " ";
	cout << endl;
	cout << "Интерполяционный многочлен Лагранжа: " << p2 << endl;*/

	Polynomial p;
	p.fileInput("input.txt");

	cout << "Многочлен p = " << p << endl;

	system("pause");

	return 0;
}