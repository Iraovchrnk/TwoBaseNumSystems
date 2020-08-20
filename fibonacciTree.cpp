#include "fibonacciTree.h"
#include <iostream>
#include <utility>
#include <iomanip>
#include <stdio.h>

using namespace std;

int FibonacciFunc(const int& i) {
	if (i < 3) return 1;
    else return FibonacciFunc(i - 1) + FibonacciFunc(i - 2);
}

FibonacciForm::FibonacciForm(int x) {
    x_ = x;
    a_ = x, b_ = 0;
    i_ = 2;
    f1_ = FibonacciFunc(i_), f2_ = FibonacciFunc(i_ + 1);
	while (true) {
        int s = (a_ / f2_ > 1 ? a_ / f2_: 1);
        int check = s * f2_;
        if (check == a_ && check > 1) check--;
        if (a_ > check) {   // +a coef, -b coef
            a_ -= s * f2_;
            b_ += s * f1_;
		}
        else if (b_ >= a_) {		// +1 rank
            i_++;
            f1_ = FibonacciFunc(i_);
            f2_ = FibonacciFunc(i_ + 1);
            int atemp = a_;
            a_ = b_ - a_;
            b_ = atemp;
		}
		else break;
	}

}

void FibonacciForm::CoutFibForm() {
    cout << x_ << " = " << a_ << "*F" << this->i_ << " + " << b_ << "*F" << this->i_ + 1 << endl;
}

FibonacciTree::FibonacciTree(int x)
{
    this->root_.SetNode(x);
    this->rootFib_.SetNode(x);
    CreateTree(&root_);
    CodeTree(&rootFib_);
}

void FibonacciTree::CodeTree(Node* nd) {
    if (nd->value_ == 1) {
        nd->left_ = NULL;
        nd->right_ = NULL;
	}
	else {
        FibonacciForm fx(nd->value_);
        nd->value_ = fx.i_;
        int a = fx.a_ - fx.b_;
        int b = fx.b_;
        Node *tempLeft = new Node();
        Node *tempRight = new Node();
        nd->right_ = NULL;
        nd->left_ = NULL;

        if (b == 0) {
            if (fx.i_ / 2 == 0) {
                tempLeft->value_ = a;
                nd->left_ = tempLeft;
                CodeTree(nd->left_);
			}
			else {
                tempRight->value_ = a;
                nd->right_ = tempRight;
                CodeTree(nd->right_);
			}
		}
		else {
            tempLeft->value_ = a;
            tempRight->value_ = b;
            nd->left_ = tempLeft;
            nd->right_ = tempRight;
            CodeTree(nd->left_);
            CodeTree(nd->right_);
		}
	}
}


void FibonacciTree::CreateTree(Node* nd) {
    if (nd->value_ == 1) {
        nd->left_ = NULL;
        nd->right_ = NULL;
	}
	else {
        FibonacciForm fx(nd->value_);
        int a = fx.a_ - fx.b_;
        int b = fx.b_;
        Node *tempLeft = new Node();
        Node *tempRight = new Node();

        if (b == 0) {
            if (fx.i_ / 2 == 0) {
                tempLeft->value_ = a;
                tempLeft->fi_ = fx.i_;
                nd->left_ = tempLeft;
                nd->right_ = NULL;
                CreateTree(nd->left_);
			}
			else {
                tempRight->value_ = a;
                tempRight->fi_ = fx.i_;
                nd->right_ = tempRight;
                nd->left_ = NULL;
                CreateTree(nd->right_);
			}
		}
		else {
            tempLeft->value_ = a;
            tempRight->value_ = b;
            tempLeft->fi_ = fx.i_;
            tempRight->fi_ = fx.i_ + 1;
            nd->left_ = tempLeft;
            nd->right_ = tempRight;
            CreateTree(nd->left_);
            CreateTree(nd->right_);
		}
	}
	
}


void FibonacciTree::PrintTreeFibForm(Node* nd) {
	if (nd != NULL) {
        FibonacciForm fNode(nd->value_);
        fNode.CoutFibForm();
        PrintTreeFibForm(nd->left_);
        PrintTreeFibForm(nd->right_);
	}
}

int _print_t(Node *tree, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
	int width = 5;

	if (!tree) return 0;

    sprintf(b, "(%03d)", tree->value_);

    int left = _print_t(tree->left_, 1, offset, depth + 1, s);
    int right = _print_t(tree->right_, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
	for (int i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';

		s[depth - 1][offset + left + width / 2] = '.';

	}
	else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';

		s[depth - 1][offset + left + width / 2] = '.';
	}
#else
	for (int i = 0; i < width; i++)
		s[2 * depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[2 * depth - 1][offset + left + width / 2 + i] = '-';

		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

	}
	else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[2 * depth - 1][offset - width / 2 + i] = '-';

		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset - width / 2 - 1] = '+';
	}
#endif

	return left + width + right;
}

void print_t(Node *tree){
	char s[20][255];
	for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

	_print_t(tree, 0, 0, 0, s);

	for (int i = 0; i < 20; i++)
		printf("%s\n", s[i]);
}

void FibonacciTree::PrintCodeTree() {
    cout << "Linear Fibonacci tree of number " << this->root_.value_ << " is:" << endl << endl;
    PrintTreeFibForm(&this->root_);
	cout << endl;
    print_t(&rootFib_);
}
