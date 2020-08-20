#pragma once

#include <cstddef>
#include <cmath>
#include <algorithm>
#define NULL nullptr

struct Node{
    int value_;
    int fi_;
    Node* left_;
    Node* right_;
    Node() : left_(NULL), right_(NULL), fi_(0) {};
    Node(int x): value_(x), left_(NULL), right_(NULL){}
    void SetNode(int x) {
        this->value_ = x;
        this->fi_ = 0;
	}
    int MaxDepth(Node* n){
		if (!n) return 0;
        return 1 + std::max(MaxDepth(n->left_), MaxDepth(n->right_));
	}

};

class FibonacciForm {
public:
    int x_;
    int f1_, f2_;
    int a_, b_;
    int i_;
	FibonacciForm(int);
    void CoutFibForm();
};

class FibonacciTree
{
private:
    Node root_;
    Node rootFib_;

public:
	FibonacciTree(int);
    void CreateTree(Node*);
    void CodeTree(Node*);
    void PrintCodeTree();
    void PrintTreeFibForm(Node*);
};
