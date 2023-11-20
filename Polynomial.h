#pragma once

#include <iostream>
#include <vector>

class Polynomial
{
private:
	std::vector<double> coefficients; //вектор коэффициентов многочлена

public:
	//конструкторы и деструктор
	Polynomial(); //конструктор без параметров
	Polynomial(const std::vector<double>& coeffs); //конструктор с передачей вектора коэффициентов
	~Polynomial(); //деструктор

	//вспомогательные методы
	void removeLeadingZeros(); //метод для удаления незначащих нулей
	void roundCoefficients(); //метод для округления коэффициентов

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
	Polynomial derivative() const; //метод взятия производной
	Polynomial gcd(const Polynomial& other) const; //метод нахождения НОД двух многочленов
	Polynomial removeMultiplicity() const; //метод устранения кратности корней
	double valueCalc(const double& other) const; //вычисление значения в точке
	double methodNewton(const double& lValue, const double& rValue); //метод Ньютона
	double methodChordsAndTangents(double lValue, double rValue) const; //комбинированный метод хорд и касательных
};