#include "Classes.h"
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

/*
	¬ектор:
		коэффициенты:
			целые числа,
			веществ.,
			комплекс.

		операции:
			сложение,
			умножение на скал€р,
			вычисление нормы,
			скал€рное произведение
*/

template<class T>
T sqrt(Complex<T> c) {
	T Re = c.GetRe(),
		Im = c.GetIm();
	return sqrt(Re * Re + Im * Im);
}


int main() {
	Complex<double> c1(2.1, 3.078);
	Complex<double> c2(5.1, -4.23);
	Complex<double> c3(-1, 0);

	
	Vector<Complex<double>> vec1(2);
	vec1.Set(0, c1);
	vec1.Set(1, c2);

	Vector<Complex<double>> vec2(2);
	vec2.Set(0, c2);
	vec2.Set(1, c3);
	


	try {

	}
	catch (const char* e) {
		cout << "Error: " << e << "\n";
	}

	return 0;
}