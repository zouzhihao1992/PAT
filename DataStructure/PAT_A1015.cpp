//
//  PAT_A1015.cpp
//  DataStructure
//
//  Created by zzh on 15/5/26.
//  Copyright (c) 2015年 zzh. All rights reserved.
//
//注意第二个测试项是 0；但是题目明明是 positive integer ，我也是醉了。
#include "PAT_A1015.h"
#include <stdio.h>
#include <math.h>
int Reverse(int n,int d)
{
    int temp[111];
    int i=0;
    int result=0;
    while (n/d!=0)
    {
        temp[i++]=n%d;
        n=n/d;
    }
    temp[i]=n%d;
    for (int j=0; j<=i; j++)
    {
        result=result*d+temp[j];
    }
    return result;
}
bool isPrime_A1015(int n)
{
    if(n<2)
    {
        return false;
    }
    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}
int main_PAT_A1015()
{
    int n,d;
    while (scanf("%d",&n)!=EOF)
    {
       
        if(n<0)
        {
            break;
        }
        scanf("%d",&d);
        if(isPrime_A1015(n))
        {
            int r=Reverse(n, d);
            if (isPrime_A1015(r))
            {
                printf("Yes\n");
                continue;
            }
        }
       
            printf("No\n");

    }
    
    return 0;
}








