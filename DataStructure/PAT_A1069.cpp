//
//  PAT_A1069.cpp
//  DataStructure
//
//  Created by zzh on 15/5/14.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1069.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int temp[4];
int* toArray(int n,int &m)
{
    int count=0;
    while(n!=0)
    {
        temp[count]=n%10;
        n=n/10;
        count++;
    }
    m=count;
    return temp;
}

int toNumber(int *a,int n)
{
    int sum=0;
    for(int i=n-1;i>=0;i--)
    {
        sum=sum*10+a[i];
    }
    
    return sum;
}
int main_PAT_A1069()
{
    int n,m;
    scanf("%d",&n);
    int *a;
    int a1,a2;
    do
    {
        a=toArray(n, m);
        
        sort(a,a+m,cmp);
        a1=toNumber(a, m);
        
        sort(a,a+m);
        a2=toNumber(a, m);
        
        if(a1==a2)
        {
            printf("%04d - %04d = 0000\n",a1,a2);
            return 0;
        }
        else
        {
            printf("%04d - %04d = %04d\n",a2,a1,a2-a1);
           
            n=a2-a1;
        }

    } while (a2-a1!=6174);
    
    return 0;
}