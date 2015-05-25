//
//  PAT_A1081.cpp
//  DataStructure
// http://www.patest.cn/contests/pat-a-practise/1081 Rational Sum
//  Created by zzh on 15/5/25.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1081.h"
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct Fraction
{
    long long up;
    long long down;
};
long long gcd(long long a, long long b)
{
    return !b ? a : gcd(b, a%b);
}
Fraction reduction(Fraction fraction)
{
    if (fraction.down < 0)
    {
        fraction.down = -fraction.down;
        fraction.up = -fraction.up;
    }
    if (fraction.up == 0)
    {
        fraction.down = 1;
    }
    else
    {
        long long d = gcd(fraction.up, fraction.down);
        fraction.up /= d;
        fraction.down /= d;
    }
    return fraction;
}
Fraction Add(Fraction a,Fraction b)
{
    Fraction result;
    a = reduction(a);
    b = reduction(b);
    result.up = a.up*b.down + a.down*b.up;
    result.down = a.down*b.down;
    result = reduction(result);
    return result;
}
void PrintFraction(Fraction fraction)
{
    if (fraction.down == 1)
    {
        printf("%lld\n", fraction.up);
        return;
    }
    else if (fraction.up < fraction.down)
    {
        printf("%lld/%lld\n", fraction.up,fraction.down);
        return;
    }
    {
        printf("%lld %lld/%lld\n", fraction.up / fraction.down, fraction.up%fraction.down, fraction.down);
        return;
    }
}
int main_PAT_A1081()
{
    int n;
    scanf("%d", &n);
    Fraction sum;
    Fraction temp;
    sum.up = 0;
    sum.down = 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld/%lld", &temp.up, &temp.down);
        temp = reduction(temp);
        sum = Add(sum, temp);
        sum = reduction(sum);
    }
    PrintFraction(sum);
    return 0;
}