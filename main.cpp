#include <iostream>
#include <vector>
#include "num23.h"
#include "fibonacciTree.h"

using namespace std;

int fibonaccFunk(const int& i) {
    if (i < 3) return 1;
    else return fibonaccFunk(i - 1) + fibonaccFunk(i - 2);
}

int main() {
    /*
    int x = 10507;
    //int x = 80;
    //int x = 20152015;//int x = 7;	//int x = 20142014;
    //int x = 15411;
    */

    int x = 0;
    cout << "Enter a number > 1 : ";
    while (cin >> x) {
        cout << endl;
        if (x <= 1) {
            cout << "Number <= 1 /n Try again" << endl;
            continue;
        }
        Num23 x23(x);
        x23.CoutNum23();
        x23.CoutBin23();
        x23.CoutAns();
        FibonacciTree  fibTree(x);
        fibTree.PrintCodeTree();
        cout << "Enter a number > 1 : ";
    }

    system("pause");
    return 0;
}
