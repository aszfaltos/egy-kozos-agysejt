#pragma once
#include <iostream>

class Rational
{
private:
    int n,d;

public:
    Rational(int x=0,int y=1) : n(x),d(y){}

    friend Rational operator+(const Rational &a, const Rational &b);

    Rational sub(const Rational &b) const;

    friend ostream& operator<<(ostream& o, const Rational &a);

};
