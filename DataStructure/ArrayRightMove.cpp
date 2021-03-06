//
//  ArrayRightMove.cpp
//  DataStructure
//  2-2 数组元素循环右移问题 难度：中等
//  Created by zzh on 15/4/15.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void rightshift(int a[],int n);
void rightshift2(int a[],int n,int shift);

int main_ArrayRightMove1()  //方法一
{
    int n,shift;
    scanf("%d",&n);
    scanf("%d",&shift);
    int a[n],i;
    for (i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0; i<shift; i++)
    {
        rightshift(a , n);
    }
    for (i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

int main_ArrayRightMove2()//方法二
{
    int n,shift;
    scanf("%d",&n);
    scanf("%d",&shift);
    int a[n],i;
    for (i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    rightshift2(a, n, shift);
    return 0;
}

void rightshift(int a[],int n)
{
    int temp=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        a[i+1]=a[i];
    }
    a[0]=temp;
}

void rightshift2(int a[],int n,int shift)
{
    int i,temp;
    for (i=0; i<n/2; i++)
    {
        temp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }
    for (i=0; i<shift/2; i++)
    {
        temp=a[i];
        a[i]=a[shift-1-i];
        a[shift-1-i]=temp;
    }
    for (i=shift; i<(n-shift)/2; i++)
    {
        temp=a[i];
        a[i]=a[shift+n-1-i];
        a[shift+n-1-i]=temp;
    }
    for (i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
}




