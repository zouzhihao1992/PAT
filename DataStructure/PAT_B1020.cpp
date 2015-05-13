//
//  PAT_B1020.cpp
//  DataStructure
//
//  Created by zzh on 15/4/25.
//  Copyright (c) 2015年 zzh. All rights reserved.
//
// 题简单，但有几个坑
// 1.库存和总价 用double存 题上写的正数不是整数
// 2.注意考虑 市场需求大于库存的情况
#include "PAT_B1020.h"
#include <stdio.h>
int findMax(double a[],int len);
int main_PAT_B1020()
{
    int N,D;
    scanf("%d%d",&N,&D);
    int i;
    double store[N];
    double price[N];
    double singal[N];
    double sum=0;
    for (i=0; i<N; i++)
    {
        scanf("%lf",&store[i]);
    }
    for (i=0; i<N; i++)
    {
        scanf("%lf",&price[i]);
        singal[i]=price[i]/store[i];
    }
    for( i=0;i<N;i++)
    {
        int Exp=findMax(singal,N);
        if (D>=store[Exp])
        {
            D-=store[Exp];
            sum+=price[Exp];
        
        }
        else
        {
            sum+=price[Exp]/store[Exp]*D;
            break;
        }
    }
    printf("%.2f",sum);
    return 0;
}

int findMax(double a[],int len)
{
    double max=a[0];
    int k=0;
    for (int i=1; i<len; i++)
    {
        if (a[i]>max)
        {
            max=a[i];
            k=i;
        }
    }
    a[k]=0;
    return k;
}