//
//  PAT_A1088.cpp
//  DataStructure
// http://www.patest.cn/contests/pat-a-practise/1088 Rational Arthmetic
//  Created by zzh on 15/5/25.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1088.h"
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct Fraction_
{
    long long up;
    long long down;
};

long long gcd_(long long a, long long b)
{
    return !b ? a : gcd_(b, a%b);
}
long long abs(long long a)
{
    if(a<0)
    {
        return -a;
    }
    
    return a;
}

Fraction_ Reduction_(Fraction_ fraction)
{
 
    if(fraction.down<0)
    {
        fraction.down=0-fraction.down;
        fraction.up=0-fraction.up;
    }
    long long d = gcd_(abs(fraction.up), abs(fraction.down));
    fraction.up /= d;
    fraction.down /= d;
    return fraction;
}

void PrintFraction_(Fraction_ fraction)
{
    if (fraction.up<0)
    {
        printf("(");
    }
    if (fraction.down == 1)
    {
        printf("%lld", fraction.up);
        
        
    }
    else if (fraction.up == 0)
    {
        printf("0");
       
    }
    else if (abs(fraction.up)<abs(fraction.down))
    {
        printf("%lld/%lld", fraction.up, fraction.down);
        
    }
    else
    {
        printf("%lld %lld/%lld", fraction.up / fraction.down, abs(fraction.up)%fraction.down, fraction.down);
        
    }
    
    if (fraction.up<0)
    {
        printf(")");
    }
}

void Add(Fraction_ a, Fraction_ b)
{
    Fraction_ result;
    a = Reduction_(a);
    b = Reduction_(b);
    result.up = a.up*b.down + a.down*b.up;
    result.down = a.down*b.down;
    result = Reduction_(result);
    PrintFraction_(a);
    printf(" + ");
    PrintFraction_(b);
    printf(" = ");
    PrintFraction_(result);
    printf("\n");
}

void Minu(Fraction_ a, Fraction_ b)
{
    Fraction_ result;
    a = Reduction_(a);
    b = Reduction_(b);
    result.up = a.up*b.down - a.down*b.up;
    result.down = a.down*b.down;
    result = Reduction_(result);
    PrintFraction_(a);
    printf(" - ");
    PrintFraction_(b);
    printf(" = ");
    PrintFraction_(result);
    printf("\n");
}

Fraction_ Multi(Fraction_ a, Fraction_ b)
{
    Fraction_ result;
    a = Reduction_(a);
    b = Reduction_(b);
    result.up = a.up*b.up;
    result.down = a.down*b.down;
    result = Reduction_(result);
    PrintFraction_(a);
    printf(" * ");
    PrintFraction_(b);
    printf(" = ");
    PrintFraction_(result);
    printf("\n");
    return result;
}

void Divide(Fraction_ a, Fraction_ b)
{
    Fraction_ result;
    a=Reduction_(a);
    b=Reduction_(b);
    
    result.up=a.up*b.down;
    result.down=a.down*b.up;
    result=Reduction_(result);
    PrintFraction_(a);
    printf(" / ");
    PrintFraction_(b);
    printf(" = ");
    if(b.up==0)
    {
        printf("Inf\n");
    }
    else
    {
        PrintFraction_(result);
        printf("\n");
    }
    
}

int main_PAT_A1088()
{
    Fraction_ a, b;
    scanf("%lld/%lld", &a.up, &a.down);
    scanf("%lld/%lld", &b.up, &b.down);
    Add(a, b);
    Minu(a,b);
    Multi(a,b);
    Divide(a,b);
    return 0;
  
}