#include "num23.h"

#include <iostream>
#include <cmath>

Num23::Num23(int x) {
    num_ = x;
    NumTo23();
}

void Num23::NumTo23coprime(int& x) {
	int p = 0;
	while (x % 2 == 0 || x % 3 == 0) {
		p++;
		x += 1;
	}
    pref_ = p;
    ans_.push_back({ p / 2, p % 2 });
}

void Num23:: NumTo23() {
    NumTo23Form();
    int xTemp = num_;
    NumTo23coprime(xTemp);
	while (xTemp > 1) {
		int l2 = int(log2(xTemp) + 10e-9);
		int l3 = 0;
        maxPows_.push_back(l2);
		int p2 = 0;
		while (l2 >= 0) {
			p2 = pow(2, l2);
			if ((xTemp - p2) % 3 == 0) {
				xTemp -= p2;
				break;
			}
			l2--;
		}
		l3 = int(log(xTemp) / log(3) + 10e-9);
		int p3 = 0;
		while (l3 >= 0) {
			p3 = pow(3, l3);
			if (xTemp  % p3 == 0) {
				if (((xTemp / p3) % 2 != 0 && (xTemp / p3) % 3 != 0) || xTemp == p3) {
					xTemp /= p3;
					break;
				}
			}
			l3--;
		}
        x23_.push_back({ l2, l3 });
	}
    maxPows_.push_back(0);
    maxPows_.erase(maxPows_.begin(), maxPows_.begin() + 1);
    NumTo23code();
    BinCode();
}

void Num23:: NumTo23code() {
    for (int i = 0; i < x23_.size(); i++) {
        ans_.push_back({ x23_[i].first - maxPows_[i] - x23_[i].second, x23_[i].second });
	}
}

void Num23::BinCode() {
    if (pref_ / 2 == 1) code23_ += '1';
    else code23_ += '0';
    if (pref_ % 2 == 1) code23_ += '1';
    else code23_ += '0';
    for (int i = 1; i < ans_.size(); i++) {
        for (int j = 0; j < ans_[i].first + 1; j++) {
            code23_ += '0';
		}
        for (int j = 0; j < ans_[i].second; j++) {
            code23_ += '1';
		}
	}
    code23_ += c;
}

void Num23::NumTo23Form() {
    int x = num_;
	int i2 = 0;
	int i3 = 0;
	while (x % 2 == 0) {
		x /= 2;
		i2++;
	}
	while (x % 3 == 0) {
		x /= 3;
		i3++;
	}
    rest_ = x;
    number23_ = { i2, i3 };
}

void Num23::Print(Num23 n) const{
	int i = 0;
    for (; i < n.x23_.size(); i++) {
        cout << "2^" << n.x23_[i].first << " + 3^" << n.x23_[i].second;
        if (i != n.x23_.size() - 1 && n.rest_ != 1) cout << "(";
	}
	i--;
	for (; i > 0; i--) cout << ")";
	//cout << endl;
}

void Num23:: CoutNum23() const {
    if (pref_ != 0) {
        cout << "(2, 3)-represintation of " << num_ << " is:" << endl;
        cout << "2^" << number23_.first << "*3^" << number23_.second;
        if(rest_ != 1) cout << "(";
        int v = rest_;
        Num23 v23(v);
        Print(v23);
        if (rest_ != 1) cout << ")" << endl;
	}
	cout << endl;
    cout << "(2, 3)-represintation of " << num_ + pref_ << " is:" << endl;
    Print(num_);
	cout << endl << endl;
}

void Num23::CoutAns() const {
	cout << "Where:" << endl;
    for (int i = 1; i < ans_.size(); i++) {
        cout << "d" << i << " = " <<  ans_[i].first << ", k" << i << " = " << ans_[i].second << endl;
	}
	cout << endl << endl;
}

void Num23:: CoutBin23() const {
    cout << "(2, 3)-code of " << num_ << " is: " << endl;
    cout << code23_ << endl;
	cout << endl;
}
