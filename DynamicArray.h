#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
#pragma once

#ifndef DynamicArray_H
#define DynamicArray_H

template<class T>
class DynamicArray {
private:
	int length;
	T* arr;

public:
	// создание
	DynamicArray(T* items, int count) {
		length = count;
		arr = new T[length];
		for (int i = 0; i < length; i++) {
			arr[i] = items[i];
		}
	};

	DynamicArray(int size) {
		length = size;
		arr = new T[length];
		for (int i = 0; i < length; i++) {
			arr[i] = 0;
		}
	};

	DynamicArray(DynamicArray<T>& dynamicArray) {
		length = dynamicArray.GetSize();
		arr = new T[length];
		for (int i = 0; i < length; i++) {
			arr[i] = dynamicArray.Get(i);
		}
	};

	// декомпозиция
	T Get(int index) {
		if (index < 0 || index >= length) {
			throw "IndexOutOfRange!";
		}
		return arr[index];
	};

	int GetSize() {
		return length;
	};

	// операции
	void Set(int index, T value) {
		if (index >= length || index < 0) {
			throw "IndexOutOfRange!";
		}
		arr[index] = value;

	};

	void Resize(int newSize) {
		if (newSize < 0) {
			throw "Incorrect size";
		}

		T* tempArr = new T[newSize];

		for (int i = 0; i < newSize; i++) {
			if (i >= length) {
				tempArr[i] = 0;
				continue;
			}
			tempArr[i] = arr[i];
		}

		delete[] arr;
		arr = tempArr;
		length = newSize;
	};

	T& operator[](int index) {
		return arr[index];
	}

	~DynamicArray() {
		delete[] arr;
	}
};

#endif DynamicArray_H