#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include "DynamicArray.h"
using namespace std;

#pragma once
#ifndef Vector_H
#define Vector_H
template<class T>
class Vector {
private:
	ArraySequence<T>* elems;

public:

	Vector() {
		elems = new ArraySequence<T>(0);
	}

	Vector(int size) {
		elems = new ArraySequence<T>(size);
	}

	Vector(T* arr, int size) {
		elems = new ArraySequence<T>(arr, size);
	};

	Vector(Vector<T>& vec) {
		int size = vec.GetSize();
		elems = new ArraySequence<T>(size);
		for (int i = 0; i < size; i++) {
			T el = vec.Get(i);
			elems->Set(i, el);
		}
	}

	// Decompose

	T Get(int index) {
		return elems->Get(index);
	}

	int GetSize() {
		return elems->GetLength();
	}

	void Set(int index, T val) {
		elems->Set(index, val);
	}

	// Operations

	void Sum(Vector<T> vec) {
		int size1 = elems->GetLength(),
			size2 = vec.GetSize();

		if (size1 != size2) {
			throw "You are not allowed to sum vectors with different sizes!";
		}

		T el;
		for (int i = 0; i < size1; i++) {
			el = elems->Get(i);
			el += vec.Get(i);
			elems->Set(i, el);
		}
	}

	void MultOnScal(T scal) {
		T el;
		for (int i = 0; i < elems->GetLength(); i++) {
			el = elems->Get(i);
			el *= scal;
			elems->Set(i, el);
		}
	}

	T CalcNorm() {
		T sum(0), el;

		for (int i = 0; i < elems->GetLength(); i++) {
			el = elems->Get(i);
			el *= el;
			sum += el;
		}

		return sqrt(sum);
	}

	T ScalarMult(Vector<T> vec) {

		int size1 = elems->GetLength(),
			size2 = vec.GetSize();

		if (size1 != size2) {
			throw "You are not allowed to multiply vectors with different sizes!";
		}

		T res(0), el(0);

		for (int i = 0; i < size1; i++) {
			el = elems->Get(i);
			el *= vec.Get(i);
			res += el;
		}

		return res;
	}

	T& operator [](int index) {
		if (index < 0 || index >= elems->GetLength()) {
			throw "IndexOutOfRange";
		}

		return (*elems)[index];
	}

	void operator += (Vector<T> vec) {
		this->Sum(vec);
	}
	
	~Vector() {
		elems->~ArraySequence<T>();
	}
	
};

#endif Vector_H