//
//  PAT_B1007.cpp
//  DataStructure
//
//  Created by zzh on 15/5/25.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_B1007.h"
#include <stdio.h>
#include <math.h>

int primes[5000];
int count=0;

bool IsPrime(int n)
{
    for(int i=2;i<=sqrt(1.0*n);i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}

void getPrimes(int n)
{
    for (int i=2; i<=n; i++)
    {
        if (IsPrime(i))
        {
            primes[count++]=i;
        }
    }
}

int main_PAT_B1007()
{
    int n;
    int result=0;
    scanf("%d ",&n);
    getPrimes(n);
    for(int i=0;i<count-1;i++)
    {
        if(primes[i+1]-primes[i]==2)
        {
            result++;
        }
    }
    printf("%d",result);
    return 0;
}








