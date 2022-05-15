#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#pragma once
#ifndef Complex_H
#define Complex_H


template<class T>
class Complex {
private:
	T Re, Im;

public:
	Complex() {
		SetRe(0);
		SetIm(0);
	}

	Complex(T _Re, T _Im) {
		SetRe(_Re);
		SetIm(_Im);
	}
	Complex(int num) {
		SetRe(num);
		SetIm(0);
	}

	T GetRe() {
		return Re;
	}

	T GetIm() {
		return Im;
	}

	void SetRe(T _Re) {
		Re = _Re;
	}

	void SetIm(T _Im) {
		Im = _Im;
	}

	void Print() {
		cout << Re << " ";
		if (Im >= 0) {
			cout << "+ " << Im << "i" << "\n";
		}
		else {
			cout << "- " << Im * (-1) << "i" << "\n";
		}
	}

	void operator = (Complex<T> c) {
		this->SetRe(c.GetRe());
		this->SetIm(c.GetIm());
	}

	void operator = (int num) {
		this->SetRe(num);
		this->SetIm(0);
	}

	void operator += (Complex<T> c) {
		T   Re1 = this->GetRe(),
			Re2 = c.GetRe(),
			Im1 = this->GetIm(),
			Im2 = c.GetIm();
		/*
			(a1+ib1) + (a2+ib2) = (a1 + a2) + i(b1 + b2)
		*/
		this->SetRe(Re1 + Re2);
		this->SetIm(Im1 + Im2);
	}

	void operator -= (Complex<T>& c) {
		T   Re1 = this->GetRe(),
			Re2 = c.GetRe(),
			Im1 = this->GetIm(),
			Im2 = c.GetIm();
		/*
			(a1+ib1) - (a2+ib2) = (a1 - a2) + i(b1 - b2)
		*/
		this->SetRe(Re1 - Re2);
		this->SetIm(Im1 - Im2);
	}

	void operator *= (Complex<T> c) {
		T Re1 = this->GetRe(),
			Re2 = c.GetRe(),
			Im1 = this->GetIm(),
			Im2 = c.GetIm();

		/*
			(a1+ib1) * (a2+ib2) = (a1a2 - b1b2) + i(a1b2 + a2b1)

		*/

		T Re_res = Re1 * Re2 - Im1 * Im2,
			Im_res = Re1 * Im2 + Re2 * Im1;
		this->SetRe(Re_res);
		this->SetIm(Im_res);
	}

};
#endif Complex_H