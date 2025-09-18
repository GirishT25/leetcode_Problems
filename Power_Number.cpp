// power of the number using recurrsion
//  a = 5 ^ 2

#include<iostream>
using namespace std;

int power(int base, int exp) {
    if (exp == 0)
        return 1;
    return base * power(base, exp - 1);
}

int main() {
    int base = 5, exp = 2;
    cout << base << " ^ " << exp << " = " << power(base, exp) << endl;
    return 0 ;
}

