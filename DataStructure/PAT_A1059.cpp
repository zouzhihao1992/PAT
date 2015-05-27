//
//  PAT_A1059.cpp
//  DataStructure
//
//  Created by zzh on 15/5/26.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1059.h"
#include <stdio.h>
#include <math.h>
const int max_A1059=100020;
int count_A1059=0;
int prime_A1059[10000];
struct factor
{
    int x;
    int count;
};
int num_A1059=0;
factor fac[10];
void printPime()
{
    bool isprime[max_A1059]={false};
    for (int i=2; i<max_A1059; i++)
    {
        if(isprime[i]==false)
        {
            prime_A1059[count_A1059++]=i;
            for (int j=i+i; j<max_A1059; j+=i)
            {
                isprime[j]=true;
            }
        }
    }
    
}
int main_PAT_A1059()
{
    printPime();
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        printf("1=1");
        return 0;
    }
    int temp=n;
    for (int i=0; prime_A1059[i]<=(int)sqrt(1.0*n); i++)
    {
        if (temp%prime_A1059[i]==0)
        {
            fac[num_A1059].x=prime_A1059[i];
            fac[num_A1059].count=0;
            
            while(temp%prime_A1059[i]==0)
            {
                fac[num_A1059].count++;
                temp/=prime_A1059[i];
            }
            num_A1059++;
        }
    }
    if(temp!=1)
    {
        printf("%d=%d",n,n);
        return 0;
    }
    printf("%d=",n);
    for (int j=0; j<num_A1059; j++)
    {
        if (fac[j].count!=1)
        {
            printf("%d^%d",fac[j].x,fac[j].count);
        }
        else
        {
            printf("%d",fac[j].x);
        }
        if(j!=num_A1059-1)
        {
            printf("*");
        }
    }
    
    
    return 0;
}







