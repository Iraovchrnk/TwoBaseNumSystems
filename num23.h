#pragma once

#include<vector>
#include<string>

using namespace std;

using num23 = vector<pair<int, int>>;

class Num23{

private:
    int num_;
    int pref_;
    num23 x23_;
    num23 ans_;
    vector<int> maxPows_;
    pair<int, int> number23_;
    string code23_;
    int rest_;
    int nm23_;
	const string c = "0111";

    void NumTo23();
    void NumTo23coprime(int&);
    void NumTo23code();
    void BinCode();
    void NumTo23Form();
    void Print(Num23) const;

public:
    Num23(int);
    void CoutAns() const;
    void CoutNum23() const;
    void CoutBin23() const;
};

