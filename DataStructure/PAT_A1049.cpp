//
//  PAT_A1049.cpp
//  DataStructure
//
//  Created by zzh on 15/5/15.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1049.h"

#include <stdio.h>
#include <math.h>

int hasOne(int n)
{
    int count=0;
    while(n!=0)
    {
        if(n%10==1)
        {
            count++;
        }
        n=n/10;
    }
    return count;
}
int main_PAT_A1049()  //超时
{
    int n;
    scanf("%d",&n);
    int count=1;
    for(int i=2;i<=n;i++)
    {
        count+=hasOne(i);
    }
    
    printf("%d",count);
    return 0;
}

int main_PAT_A1049_2()
{
    int n;
    scanf("%d",&n);
    int left=0,right=0,mid,m,count=0;
    int sum=0;
    int temp=n;
    while(temp!=0)
    {
        temp=temp/10;
        count++;
    }
    temp=n;
    int a[count];
    int i;
    for(i=0;i<count;i++)
    {
        a[i]=temp%10;
        temp=temp/10;
    }
    for(i=0;i<count;i++)
    {
        mid=a[i];
        m=i;
        for(int j=i-1;j>=0;j--)
        {
            right=right*10+a[j];
        }
        for(int k=count-1;k>i;k--)
        {
            left=left*10+a[k];
        }
        if(mid==0)
        {
            sum+=left*pow(10,m);
        }
        else if(mid==1)
        {
            sum+=left*pow(10, m)+right+1;
        }
        else if(mid>1)
        {
            sum+=(left+1)*pow(10, m);
        }
        
        left=0;
        right=0;
    }
    printf("%d",sum);
    return 0;
}
















