#include <iostream>
#include "rat.h"

using namespace std;

Rational operator+(const Rational &a, const Rational &b)
{
    return Rational(a.n*b.d+b.n*a.d,a.d*b.d);
}

Rational Rational::sub(const Rational &b) const
{
    return Rational(n*b.d-b.n*d,d*b.d);
}

ostream& operator<<(ostream& o, const Rational &a)
{
    o<<a.n<<"/"<<a.d;
    return o;
}
