#include "Polynomial.h"
#include "myFunctions.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

    double lValue = 2, rValue = 5;
    cout << "F(x) = 1 / log(x)\n";
    cout << "Интеграл от 2 до 5\n";

    double value1 = rectangleMethod(lValue, rValue, 100000);
    double value2 = trapezoidMethod(lValue, rValue, 100000);
    double value3 = simpsonsMethod(lValue, rValue, 100000);

    cout << "Метод прямоугольников: " << value1 << endl;
    cout << "Метод трапеций: " << value2 << endl;
    cout << "Метод Симпсона: " << value3 << endl;

	system("pause");

	return 0;
}
