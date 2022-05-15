#include "Node.h"
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#pragma once

#ifndef LinkedList_H
#define LinkedList_H

template<class T>
class LinkedList {
private:
	Node<T>* head, * tail;
public:
	// создание
	LinkedList(T* items, int count) {
		if (items[0] == NULL || count <= 0) {
			throw "Undefined value";
		}

		for (int i = 0; i < count; i++) {
			this->Append(items[i]);
		}
	};

	LinkedList() {
		head = NULL; // first node
		tail = NULL; // last node
	};

	LinkedList(LinkedList<T>& list) {
		Node<T>* el = NULL, * t = NULL;
		head = new Node<T>;
		int size = list.GetLength();
		head->data = list.GetFirst();
		t = head;

		for (int i = 1; i < size; i++) {
			el = new Node<T>;
			el->data = list.Get(i);
			t->next = el;
			t = t->next;
		}
	};

	// декомпозиция

	T GetFirst() {
		if (head == NULL) {
			throw "IndexOutOfRange";
		}

		return head->data;
	};

	T GetLast() {
		if (head == NULL) {
			throw  "IndexOutOfRange";
		}

		Node<T>* tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		return tmp->data;
	};

	T Get(int index) {
		int size = GetLength();
		if (index < 0 || index >= size) {
			throw "IndexOutOfRange!";
		}

		Node<T>* tmp = head;
		for (int i = 0; i < size; i++) {
			if (i == index) {
				return tmp->data;
			}
			tmp = tmp->next;
		}
		return 0;
	};

	LinkedList<T>* GetSubList(int startIndex, int endIndex) {
		int size = this->GetLength();
		if (startIndex < 0 || startIndex >= size || endIndex < 0 || endIndex >= size) {
			throw "IndexOutOfRange!";
		}

		LinkedList<T>* res = new LinkedList();

		for (int i = startIndex; i <= endIndex; i++) {
			res->Append(Get(i));
		}
		return res;
	};

	int GetLength() {
		int c = 0;
		Node<T>* tmp = head;
		if (tmp == NULL) return 0;
		while (tmp->next != NULL) {
			c++;
			tmp = tmp->next;
		}
		c++;
		return c;
	};

	// операции
	void Append(T item) {
		Node<T>* tmp = new Node<T>;
		tmp->data = item;
		tmp->next = NULL;

		if (head == NULL) { // no linked list yet
			head = tmp;
			tail = tmp;
		}
		else { // add one more node
			tail->next = tmp;
			tail = tail->next;
		}
	};

	void Prepend(T item) {
		Node<T>* tmp = new Node<T>;
		tmp->data = item;
		tmp->next = head;
		head = tmp;
	};

	void InsertAt(int index, T item) {
		int size = GetLength();

		if (index < 0 || index > size) {
			throw "IndexOutOfRange!";
		}

		if (index == size) {
			Append(item);
		}
		else if (index == 0) {
			Prepend(item);
		}
		else {
			Node<T>* el = new Node<T>;
			el->data = item;

			Node<T>* tmp = head;
			for (int i = 0; i < index - 1; i++) {
				tmp = tmp->next;
			}
			el->next = tmp->next;
			tmp->next = el;
		}

	};

	LinkedList<T>* Concat(LinkedList<T>* list) {
		LinkedList<T>* res = new LinkedList<T>();
		Node<T>* el = head;
		while (el != NULL) {
			res->Append(el->data);
			el = el->next;
		}

		for (int i = 0; i < list->GetLength(); i++) {
			res->Append(list->Get(i));
		}

		return res;
	};

	~LinkedList() {
		Node<T>* el = head, * tmp;
		while (el != NULL) {
			tmp = el;
			el = el->next;
			delete tmp;
		}
	}
};

#endif LinkedList_h