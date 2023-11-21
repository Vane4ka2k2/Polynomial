#pragma once

#include <iostream>
#include <vector>

class Polynomial
{
private:
	std::vector<double> coefficients; //вектор коэффициентов многочлена

	//вспомогательные методы

	void removeLeadingZeros(); //метод для удаления незначащих нулей
	void roundCoefficients(); //метод для округления коэффициентов

public:
	//конструкторы и деструктор

	Polynomial(); //конструктор без параметров
	Polynomial(const std::vector<double>& coeffs); //конструктор с передачей вектора коэффициентов
	~Polynomial(); //деструктор

	//ввод и вывод многочлена

	void input(); //ввод многочлена с клавиатуры
	void print() const; //вывод многочлена в консоль
	friend std::istream& operator>>(std::istream& is, Polynomial& poly); //перегрузка оператора >> для istream
	friend std::ostream& operator<<(std::ostream& os, Polynomial& poly); //перегрузка оператора << для ostream

	//перегрузка логических операторов

	bool operator!=(const Polynomial& other) const; //перегрузка оператора !=
	bool operator==(const Polynomial& other) const; //перегрузка оператора ==
	bool operator>(const Polynomial& other) const; //перегрузка оператора >

	//перегрузка арифметических операторов

	Polynomial operator+(const Polynomial& other) const; //перегрузка оператора + для многочлена
	Polynomial operator+(const double& other) const; //перегрузка оператора + для числа
	Polynomial operator-(const Polynomial& other) const; //перегрузка оператора - для многочлена
	Polynomial operator-(const double& other) const; //перегрузка оператора - для числа
	Polynomial operator*(const Polynomial& other) const; //перегрузка оператора * для многочлена
	Polynomial operator*(const double& other) const; //перегрузка оператора * для числа
	Polynomial operator/(const Polynomial& other) const; //перегрузка оператора / для многочлена
	Polynomial operator/(const double& other) const; //перегрузка оператора / для числа
	Polynomial operator%(const Polynomial& other) const; //перегрузка оператора % для многочлена

	//основные методы

	//output
	//	Polynomial - производная многочлена
	Polynomial derivative() const; //метод взятия производной

	//input
	//	Polynomial - второй многочлен
	//output
	//	Polynomial - НОД
	Polynomial gcd(const Polynomial& other) const; //метод нахождения НОД двух многочленов

	//output
	//	Poynomial - многочлен без кратных корней
	Polynomial removeMultiplicity() const; //метод устранения кратности корней

	//input
	//	double - точка, в которой вычисляется значение
	//output
	//	double - значение многочлена в этой точке
	double valueCalc(const double& other) const; //вычисление значения в точке

	//input
	//	double - левая точка отрезка
	//	double - правая точка отрезка
	//output
	//	double - примерное значение точки
	double methodNewton(const double& lValue, const double& rValue); //метод Ньютона

	//input
	//	double - левая точка отрезка
	//	double - правая точка отрезка
	//output
	//	double - примерное значение точки
	double methodChordsAndTangents(double lValue, double rValue) const; //комбинированный метод хорд и касательных
};