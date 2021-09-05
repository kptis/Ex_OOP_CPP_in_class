#include <iostream>
#include "PhanSoX.h"
using namespace std;

int main()
{
    PhanSoX a(4,5);      //Khai bao phan so 4/5
    PhanSoX b(2);        //Khai bao phan so 2/1 (= 2)
    PhanSoX c,d;         // Khai bao 2 phan so bang 0

    c = a+b;               //Tinh 4/5 + 2/1 = 14/5

    d = a*b;               //Tinh 4/5 * 2/1 = 8/5

    cout << a << " + " << b << " = " << c << endl;

    cout << a << " * " << b << " = " << d << endl;

    if(a > b)
        cout << "a lon hon b." << endl;
    else if(a==b)
        cout << "a bang b." << endl;
    else
        cout << "a nho hon b." << endl;

    return 0;
}

