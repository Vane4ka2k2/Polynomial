#include "Polynomial.h"

Polynomial::Polynomial()
{
	coefficients = { 0 }; //инициализация вектора
}

Polynomial::Polynomial(const std::vector<double>& coeffs)
{
	coefficients = coeffs; //копирование вектора коэффициентов
}

Polynomial::~Polynomial()
{

}

void Polynomial::removeLeadingZeros()
{
	while (coefficients.size() > 1 && coefficients.back() == 0) //пока размер вектора больше одного и последний элемент вектора равен нулю
	{
		coefficients.pop_back(); //удаляем последний элемент
	}
}

void Polynomial::roundCoefficients()
{
	for (size_t i = 0; i < coefficients.size(); ++i)
	{
		coefficients[i] = round(coefficients[i] * 1000) / 1000; //округляем каждый элемент вектора
	}
}

void Polynomial::input()
{
	int degree = 0; //степень многочлена
	std::cout << "Введите степень многочлена: ";	std::cin >> degree; //Ввод степени многочлена с клавиатуры

	coefficients.resize(degree + 1); //задаём размер вектора

	for (int i = degree; i >= 0; --i)
	{
		std::cout << "Введите коэффициент при x^" << i << ": ";
		std::cin >> coefficients[i];
	}
}

void Polynomial::print() const
{
	bool isFirstValue = true;

	for (int i = coefficients.size() - 1; i >= 0; --i)
	{
		if (coefficients[i] != 0.0)
		{
			if (!isFirstValue)
			{
				if (coefficients[i] > 0)
				{
					std::cout << " + ";
				}
				else
				{
					std::cout << " - ";
				}
			}
			else
			{
				isFirstValue = false;

				if (coefficients[i] < 0)
				{
					std::cout << " - ";
				}
			}

			double absCoeff = fabs(coefficients[i]);

			if (i == 0 || absCoeff != 1.0)
			{
				std::cout << absCoeff;
			}
			if (i > 0)
			{
				std::cout << "x";
				if (i > 1)
				{
					std::cout << "^" << i;
				}
			}
		}
	}

	if (isFirstValue)
	{
		std::cout << "0";
	}
}

bool Polynomial::operator!=(const Polynomial& other) const
{
	return coefficients != other.coefficients;
}

bool Polynomial::operator==(const Polynomial& other) const
{
	return coefficients == other.coefficients;
}

bool Polynomial::operator>(const Polynomial& other) const
{
	size_t maxDegree = 
		std::max(coefficients.size(), other.coefficients.size()); //большая степень двух многочленов

	for (size_t i = maxDegree; i > 0; --i)
	{
		double thisCoeff = 
			(i <= coefficients.size()) ? coefficients[i - 1] : 0; //получение коэффициента левого многочлена для сравнения
		double otherCoeff = 
			(i <= other.coefficients.size()) ? other.coefficients[i - 1] : 0; //получение коэффициента правого многочлена для сравнения

		if (thisCoeff > otherCoeff)
			return true; //левый многочлен больше
		else if (thisCoeff < otherCoeff)
			return false; //правый многочлен больше
	}

	return false; //многочлены равны
}

Polynomial Polynomial::operator+(const Polynomial& other) const
{
	std::vector<double> resultVector(
		std::max(coefficients.size(), other.coefficients.size()), 0); //задаём размер результирующего вектора

	for (size_t i = 0; i < coefficients.size(); ++i)
	{
		resultVector[i] += coefficients[i]; //помещаем коэффициенты левого многочлена в результирующий вектор
	}

	for (size_t i = 0; i < other.coefficients.size(); ++i)
	{
		resultVector[i] += other.coefficients[i]; //складываем коэффициенты результирующего вектора с правым многочленом
	}

	Polynomial result(resultVector);

	result.roundCoefficients(); //округление коэффициентов
	result.removeLeadingZeros(); //удаление незначащих нулей

	return result;
}

Polynomial Polynomial::operator+(const double& other) const
{
	std::vector<double> resultVector(coefficients); //вектор с коэффициентами многочлена
	
	resultVector[0] += other; //Сложение свободного члена с числом

	Polynomial result(resultVector);

	result.roundCoefficients(); //округление коэффициентов
	result.removeLeadingZeros(); //удаление незначащих нулей

	return result;
}

Polynomial Polynomial::operator-(const Polynomial& other) const
{
	std::vector<double> resultVector(
		std::max(coefficients.size(), other.coefficients.size()), 0); //задаём размер результирующего вектора

	for (size_t i = 0; i < coefficients.size(); ++i)
	{
		resultVector[i] += coefficients[i]; //помещаем коэффициенты левого многочлена в результирующий вектор
	}

	for (size_t i = 0; i < other.coefficients.size(); ++i)
	{
		resultVector[i] -= other.coefficients[i]; //вычитаем коэффициенты правого многочлена из результирующего вектора
	}

	Polynomial result(resultVector);

	result.roundCoefficients(); //округление коэффициентов
	result.removeLeadingZeros(); //удаление незначащих нулей

	return result;
}

Polynomial Polynomial::operator-(const double& other) const
{
	std::vector<double> resultVector(coefficients); //вектор с коэффициентами многочлена

	resultVector[0] -= other; //вычитание числа из свободного члена

	Polynomial result(resultVector);

	result.roundCoefficients(); //округление коэффициентов
	result.removeLeadingZeros(); //удаление незначащих нулей

	return result;
}

Polynomial Polynomial::operator*(const Polynomial& other) const
{
	std::vector<double> resultVector(
		coefficients.size() + other.coefficients.size() - 1, 0.0); //задаём размер результирующего вектора

	//во внешнем цикле проходим по левому многочлену
	//во внутреннем проходим по правому многочлену
	//перемножаем все коэффициенты
	for (size_t i = 0; i < coefficients.size(); ++i)
	{
		for (size_t j = 0; j < other.coefficients.size(); ++j)
		{
			resultVector[i + j] += coefficients[i] * other.coefficients[j];
		}
	}

	Polynomial result(resultVector);

	result.roundCoefficients(); //округление коэффициентов
	result.removeLeadingZeros(); //удаление незначащих нулей

	return result;
}

Polynomial Polynomial::operator*(const double& other) const
{
	std::vector<double> resultVector(coefficients);

	for (size_t i = 0; i < coefficients[i]; ++i)
	{
		resultVector[i] *= other;
	}

	Polynomial result(resultVector);

	result.roundCoefficients(); //округление коэффициентов
	result.removeLeadingZeros(); //удаление незначащих нулей

	return result;
}

Polynomial Polynomial::operator/(const Polynomial& other) const
{
	std::vector<double> dividend(coefficients); //вектор коэффициентов делимого
	std::vector<double> quotient(
		(dividend.size() - 1) - (other.coefficients.size() - 1) + 1, 0.0); //вектор коэффициентов частного

	while (dividend.size() >= other.coefficients.size()) //пока размер делимого больше размера делителя
	{
		double factor = dividend.back() / other.coefficients.back(); //вычисляем число частного
		quotient[(dividend.size() - 1) - (other.coefficients.size() - 1)] = factor; //вычисляем индекс для коэффициента частного и записываем его туда

		for (size_t i = 0; i < other.coefficients.size(); ++i)
		{
			dividend[dividend.size() - i - 1] -= 
				factor * other.coefficients[other.coefficients.size() - i - 1]; //получаем остаток (новое делимое)
		}

		while (!dividend.empty() && dividend.back() == 0)
		{
			dividend.pop_back(); //удаление незначащих нулей
		}
	}

	Polynomial result(quotient);

	result.roundCoefficients();

	return result;
}

Polynomial Polynomial::operator/(const double& other) const
{
	std::vector<double> resultVector(coefficients); //задаём результирующий вектор

	for (size_t i = 0; i < resultVector.size(); i++)
	{
		resultVector[i] /= other; //делим каждый коэффициент на число
	}

	Polynomial result(resultVector);

	result.roundCoefficients(); //округление коэффициентов
	result.removeLeadingZeros(); //удаление незначащих нулей

	return result;
}

Polynomial Polynomial::operator%(const Polynomial& other) const
{
	std::vector<double> dividend(coefficients); //вектор коэффициентов делимого

	while (dividend.size() >= other.coefficients.size()) //пока размер делимого больше размера делителя
	{
		double factor = dividend.back() / other.coefficients.back(); //вычисляем число частного

		for (size_t i = 0; i < other.coefficients.size(); ++i)
		{
			dividend[dividend.size() - i - 1] -=
				factor * other.coefficients[other.coefficients.size() - i - 1]; //получаем остаток от деления
		}

		while (!dividend.empty() && dividend.back() == 0)
		{
			dividend.pop_back(); //удаление незначащих нулей
		}
	}

	Polynomial result(dividend);

	result.roundCoefficients(); //округление коэффициентов
	result.removeLeadingZeros(); //удаление незначащих нулей

	return result;
}

std::pair<Polynomial, Polynomial> Polynomial::division(const Polynomial& other)
{
	return std::pair<Polynomial, Polynomial>(*this / other, *this % other);
}

Polynomial Polynomial::derivative() const
{
	std::vector<double> resultVector(coefficients.size() - 1, 0.0);

	for (size_t i = 1; i < coefficients.size(); ++i)
	{
		resultVector[i - 1] = coefficients[i] * i;
	}

	Polynomial result(resultVector);

	result.roundCoefficients(); //округление коэффициентов
	result.removeLeadingZeros(); //удаление незначащих нулей

	return result;
}

Polynomial Polynomial::gcd(const Polynomial& other) const
{
	Polynomial dividend = *this; //делимое
	Polynomial divisor = other; //делитель
	Polynomial quotient = dividend / divisor; //частное
	Polynomial remainder = dividend % divisor; //остаток

	while (!remainder.coefficients.empty()) //пока есть остаток
	{
		dividend = divisor;
		divisor = remainder;
		quotient = dividend / divisor;
		remainder = dividend % divisor;
	}

	return divisor;
}

Polynomial Polynomial::removeMultiplicity() const
{
	return *this / this->gcd(this->derivative());
}

double Polynomial::valueCalc(const double& other) const
{
	double result = coefficients[0];
	
	for (size_t i = 1; i < coefficients.size(); ++i)
	{
		result += coefficients[i] * pow(other, i);
	}

	return result;
}

double Polynomial::methodNewton(const double& lValue, const double& rValue)
{
	double eps = 0.001; //epsilon
	double result = 0.0;
	double delta = 1.0;
	Polynomial firstDer = this->derivative(); //первая производная
	Polynomial secondDer = firstDer.derivative(); //вторая производная
	
	//Если f(lValue)f’’(lValue) > 0, то result = lValue
	if ((this->valueCalc(lValue) * secondDer.valueCalc(lValue)) > 0)
	{
		result = lValue;
	}
	//иначе если f(rValue)f’’(rValue) > 0, то result = rValue
	else if ((this->valueCalc(rValue) * secondDer.valueCalc(rValue)) > 0)
	{
		result = rValue;
	}

	while (fabs(delta) > eps)
	{
		delta = this->valueCalc(result) / firstDer.valueCalc(result); //Δ = f(result)/f’(result)
		result = result - delta;
	}

	return result;
}

double Polynomial::methodChordsAndTangents(double lValue, double rValue) const
{
	double eps = 0.001; //epsilon
	Polynomial firstDer = this->derivative(); //первая производная
	Polynomial secondDer = firstDer.derivative(); //вторая производная

	while (fabs(lValue - rValue) > (2 * eps)) // пока |lValue − rValue| > 2ε
	{ 
		//Если f(lValue)f’’(lValue) < 0, то lValue = lValue − f(lValue)(lValue − rValue)/(f(lValue) − f(rValue))
		if ((this->valueCalc(lValue) * secondDer.valueCalc(lValue)) < 0)
		{
			lValue = lValue - this->valueCalc(lValue) * (lValue - rValue) / (this->valueCalc(lValue) - this->valueCalc(rValue));
		}
		//иначе если f(lValue)f’’(lValue) > 0, то lValue = lValue − f(lValue)/f’(lValue)
		else if ((this->valueCalc(lValue) * secondDer.valueCalc(lValue)) > 0)
		{
			lValue = lValue - (this->valueCalc(lValue) / firstDer.valueCalc(lValue));
		}

		//Если f(rValue)f’’(rValue) < 0, то rValue = rValue − f(rValue)(rValue − lValue)/(f(rValue) − f(lValue))
		if ((this->valueCalc(rValue) * secondDer.valueCalc(rValue)) < 0)
		{
			rValue = rValue - this->valueCalc(rValue) * (rValue - lValue) / (this->valueCalc(rValue) - this->valueCalc(lValue));
		}
		//иначе если f(rValue)f’’(rValue) > 0, то rValue = rValue − f(rValue) / f’(rValue)
		else if ((this->valueCalc(rValue) * secondDer.valueCalc(rValue)) > 0)
		{
			rValue = rValue - (this->valueCalc(rValue) / firstDer.valueCalc(rValue));
		}
	}

	return ((lValue + rValue) / 2);
}

std::istream& operator>>(std::istream& is, Polynomial& poly)
{
	int degree = 0;
	std::cout << "Введите степень многочлена: ";
	is >> degree;

	poly.coefficients.resize(degree + 1);

	for (int i = degree; i >= 0; --i)
	{
		std::cout << "Введите коэффициент при x^" << i << ": ";
		is >> poly.coefficients[i];
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, Polynomial& poly)
{
	bool isFirstValue = true;

	for (int i = poly.coefficients.size() - 1; i >= 0; --i)
	{
		if (poly.coefficients[i] != 0.0)
		{
			if (!isFirstValue)
			{
				if (poly.coefficients[i] > 0)
				{
					os << " + ";
				}
				else
				{
					os << " - ";
				}
			}
			else
			{
				isFirstValue = false;

				if (poly.coefficients[i] < 0)
				{
					os << " - ";
				}
			}

			double absCoeff = fabs(poly.coefficients[i]);

			if (i == 0 || absCoeff != 1.0)
			{
				os << absCoeff;
			}
			if (i > 0)
			{
				os << "x";
				if (i > 1)
				{
					os << "^" << i;
				}
			}
		}
	}

	if (isFirstValue)
	{
		os << "0";
	}

	return os;
}
