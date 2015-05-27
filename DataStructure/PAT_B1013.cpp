//
//  PAT_B1013.cpp
//  DataStructure
//
//  Created by zzh on 15/5/25.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_B1013.h"
#include <stdio.h>
#include <math.h>

int primes_[50000];
int count_=0;
const int max=1000001;
bool IsPrime_(int n)
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
void getPrimes_(int n)
{
    for (int i=2; i<=1000001; i++)
    {
        if (IsPrime_(i))
        {
            primes_[count_++]=i;
        }
        if(count_>n)
        {
            return;
        }
    }
}
void getPrimes_2(int n)
{
    bool isPrime[max]={false};
    for (int i=2; i<max; i++)
    {
        if(isPrime[i]==false)
        {
            primes_[count_++]=i;
            if(count_>n)
            {
                return;
            }
            for(int j=i+i;j<max;j=j+i)
            {
                isPrime[j]=true;
            }
        }
    }
    
}
int main_PAT_B1013()
{
    int m,n;
    scanf("%d%d",&m,&n);
    getPrimes_2(n);
    int j=0;
    for (int i=m; i<=n; i++)
    {
        printf("%d",primes_[i-1]);
        j++;
        if(j%10==0)
        {
            printf("\n");
        }
        else if(i!=n)
        {
            printf(" ");
        }
    }
    return 0;
}








