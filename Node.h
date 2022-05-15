#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
#pragma once

#ifndef NODE_H
#define NODE_H
template<class T>
struct Node {
	T data;
	Node* next;

public:
	Node() {
		data = 0;
		next = NULL;
	}
};
#endif NODE_H

