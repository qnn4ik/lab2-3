#pragma once
#include "Node.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sequence.h"
#include "Vector.h"
#include "Complex.h"
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

template<class T>
Complex<T>& operator + (Complex<T>& c1, Complex<T>& c2) {
	Complex<T> res = 0;
	res.SetRe(c1.GetRe());
	res.SetIm(c1.GetIm());
	res += c2;
	return res;
}

template<class T>
Vector<T> operator + (Vector<T> vec1, Vector<T> vec2) {
	int size1 = vec1.GetSize(), size2 = vec2.GetSize();

	if (size1 != size2) {
		throw "You can not summary vectors with different sizes";
	}

	Vector<T> res(size1);

	T el;
	for (int i = 0; i < size1; i++) {
		el = vec1[i];
		el += vec2[i];
		res[i] = el;
	}
	return res;
}

template<class T>
ostream& operator << (ostream& COUT, LinkedList<T> list) {
	int size = list.GetLength();
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			COUT << list.Get(i) << '\n';
			break;
		}
		COUT << list.Get(i) << " -> ";
	}
	return COUT;
}

template<class T>
ostream& operator << (ostream& COUT, Complex<T> c) {
	COUT << c.GetRe() << " ";
	if (c.GetIm() >= 0) {
		COUT << "+ " << c.GetIm() << "i" << "\n";
	}
	else {
		COUT << "- " << c.GetIm() * (-1) << "i" << "\n";
	}
	return COUT;
}

template<class T>
ostream& operator << (ostream& COUT, DynamicArray<T> arr) {
	for (int i = 0; i < arr.GetSize(); i++) {
		COUT << arr[i] << " ";
	}
	return COUT;
}

template<class T>
ostream& operator << (ostream& COUT, Vector<T> v) {
	int size = v.GetSize();
	for (int i = 0; i < size; i++) {
		COUT << v.Get(i) << " ";
	}
	return COUT;
}
