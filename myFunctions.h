#include <cmath>

//функция
double f(double x)
{
	return 1 / log(x);
};

//метод прямоугольников
double rectangleMethod(double lValue, double rValue, int n) {
    double h = (rValue - lValue) / n;
    double result = 0.0;

    for (int i = 0; i < n; ++i) {
        double x_i = lValue + i * h;
        result += f(x_i);
    }

    return h * result;
};

//метод трапеций
double trapezoidMethod(double lValue, double rValue, int n)
{
    double h = (rValue - lValue) / n;
    double result = 0.5 * (f(lValue) + f(rValue));

    for (int i = 1; i < n; ++i) {
        double x_i = lValue + i * h;
        result += f(x_i);
    }

    return h * result;
};

//метод Симпсона
double simpsonsMethod(double lValue, double rValue, int n)
{
    double h = (rValue - lValue) / n;
    double result = f(lValue) + f(rValue);

    for (int i = 1; i < n; i += 2) {
        double x_i = lValue + i * h;
        result += 4 * f(x_i);
    }

    for (int i = 2; i < n - 1; i += 2) {
        double x_i = lValue + i * h;
        result += 2 * f(x_i);
    }

    return h / 3 * result;
};
