#include "DynamicArray.h"
#include "LinkedList.h"
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#pragma once

#ifndef Sequence_T_H
#define Sequence_T_H

template<class T>
class Sequence {
public:
	
	virtual T GetFirst() = 0;

	virtual T GetLast() = 0;

	virtual T Get(int index) = 0;

	virtual int GetLength() = 0;

	virtual void Append(T item) = 0;

	virtual void Prepand(T item) = 0;

	virtual void InsertAt(int index, T item) = 0;
};

template<class T>
class ArraySequence : public Sequence<T> {
private:
	DynamicArray<T>* arr;

public:
	ArraySequence(T* items, int count) {
		arr = new DynamicArray<T>(items, count);
	}

	ArraySequence(int size) {
		arr = new DynamicArray<T>(size);
	}

	ArraySequence(DynamicArray<T>& from) {
		arr = new DynamicArray<T>(from);
	};

	T GetFirst() {
		return arr->Get(0);
	};

	T GetLast() {
		return arr->Get(arr->GetSize() - 1);
	};

	T Get(int index) {
		return arr->Get(index);
	}

	int GetLength() {
		return arr->GetSize();
	}

	void Set(int index, T item) {
		if (index >= arr->GetSize() || index < 0) {
			throw "IndexOutOfRange!";
		}
		arr->Set(index, item);
	}

	void Append(T item) {
		arr->Resize(arr->GetSize() + 1);
		arr->Set(arr->GetSize() - 1, item);
	}

	void Prepand(T item) {
		int size = arr->GetSize() + 1;
		DynamicArray<T>* extra = new DynamicArray<T>(size);
		extra->Set(0, item);

		for (int i = 1; i < size; i++) {
			extra->Set(i, arr->Get(i - 1));
		}
		arr->~DynamicArray();
		arr = extra;
	}

	void InsertAt(int index, T item) {
		int size = arr->GetSize();

		if (index < 0 || index > size) throw "IndexOutOfRange!";

		if (index == 0) Prepand(item);
		else if (index == size) Append(item);
		else {
			size++;
			DynamicArray<T>* extra = new DynamicArray<T>(size);

			for (int i = 0; i < index; i++) { // copy before ind
				extra->Set(i, arr->Get(i));
			}
			extra->Set(index, item);
			for (int i = index + 1; i < size; i++) {
				extra->Set(i, arr->Get(i - 1));
			}
			arr->~DynamicArray();
			arr = extra;
		}
	}

	T& operator[](int index) {
		return (*arr)[index];
	}

	~ArraySequence() {
		arr->~DynamicArray();
	}


};

template<class T>
class LinkedListSequence : public Sequence<T> {
private:
	LinkedList<T>* list;
public:
	LinkedListSequence() {
		list = new LinkedList<T>();
	}
	LinkedListSequence(T* items, int count) {
		list = new LinkedList<T>(items, count);
	}
	LinkedListSequence(LinkedList<T>& from) {
		list = new LinkedList<T>(from);
	}

	T GetFirst() {
		return list->GetFirst();
	};

	T GetLast() {
		return list->GetLast();
	};

	T Get(int index) {
		return list->Get(index);
	}

	int GetLength() {
		return list->GetLength();
	}

	void Append(T item) {
		list->Append(item);
	}

	void Prepand(T item) {
		list->Prepend(item);
	}

	void InsertAt(int index, T item) {
		list->InsertAt(index, item);
	}

	LinkedListSequence<T>* GetSubSequence(int startIndex, int endIndex) {
		int size = list->GetLength();
		if (startIndex < 0 || startIndex >= size || endIndex < 0 || endIndex >= size) {
			throw "IndexOutOfRange!\n";
		}

		LinkedListSequence<T>* res = new LinkedListSequence();

		for (int i = startIndex; i <= endIndex; i++) {
			res->Append(list->Get(i));
		}

		return res;
	}


	LinkedListSequence<T>* Concat(LinkedListSequence<T>* from) {
		int size1 = this->GetLength(), size2 = from->GetLength();
		LinkedListSequence<T>* res = new LinkedListSequence<T>();

		for (int i = 0; i < size1; i++) {
			res->Append(Get(i));
		}

		for (int i = 0; i < size2; i++) {
			res->Append(from->Get(i));
		}

		return res;

	}


	~LinkedListSequence() {
		list->~LinkedList();
	}

};
#endif Sequence_T_H