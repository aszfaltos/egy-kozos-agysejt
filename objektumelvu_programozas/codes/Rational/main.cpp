#include <iostream>
#include "rat.h"

using namespace std;

int main()
{
    Rational r(2,4);
    Rational r2(1,3);

    Rational r3=r+r2;
    Rational r4=r.sub(r2);

    cout << r3 <<endl;

    return 0;
}
