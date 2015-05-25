//
//  PAT_A1088.cpp
//  DataStructure
// http://www.patest.cn/contests/pat-a-practise/1088 Rational Arthmetic
//  Created by zzh on 15/5/25.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1088.h"
#include <stdio.h>
struct Fraction
{
    long long up;
    long long down;
};

long long gcd(long long a, long long b)
{
    return !b ? a : gcd(b, a%b);
}
Fraction Reduction(Fraction fraction)
{
    long long d = gcd(fraction.up, fraction.down);
    fraction.up /= d;
    fraction.down /= d;
    return fraction;
}
void PrintFraction(Fraction fraction)
{
    if (fraction.down == 1)
    {
        printf("%lld", fraction.up);
        return;
        
    }
    else if (fraction.up == 0)
    {
        printf("0");
        return;
    }
    else if (fraction.up<fraction.down)
    {
        printf("%lld/%lld", fraction.up, fraction.down);
        return;
    }
    else
    {
        printf("%lld,%lld/%lld", fraction.up / fraction.down, fraction.up%fraction.down, fraction.down);
        return;
    }
}
void Add(Fraction a, Fraction b)
{
    Fraction result;
    a = Reduction(a);
    b = Reduction(b);
    result.up = a.up*b.down + a.down*b.up;
    result.down = a.down*b.down;
    result = Reduction(result);
    PrintFraction(a);
    printf("+");
    PrintFraction(b);
    printf("=");
    PrintFraction(result);
}
Fraction Minu(Fraction a, Fraction b)
{
    Fraction result;
    a = Reduction(a);
    b = Reduction(b);
    result.up = a.up*b.down - a.down*b.up;
    result.down = a.down*b.down;
    result = Reduction(result);
    return result;
}
Fraction Multi(Fraction a, Fraction b)
{
    Fraction result;
    a = Reduction(a);
    b = Reduction(b);
    result.up = a.up*b.up;
    result.down = a.down*b.down;
    result = Reduction(result);
    return result;
}
Fraction Divide(Fraction a, Fraction b)
{
    long long temp = b.up;
    b.up = b.down;
    b.down = temp;
    return Multi(a, b);	
}
int main_PAT_A1088()
{
    Fraction a, b;
    scanf("%lld/%lld", &a.up, &a.down);
    scanf("%lld%lld", &b.up, &b.down);
    Add(a, b);
    return 0;
}