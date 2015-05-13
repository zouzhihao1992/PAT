//
//  PAT_A1085.cpp
//  DataStructure
//
//  Created by zzh on 15/5/11.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1085.h"

#include "stdio.h"
#include <algorithm>
using namespace std;
//返回第一个比x大的数的下标
int my_upper_bound(int *a,int left,int right,long long x)
{
    ++right;
    int mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(a[mid]>x)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
    }
    return left;
}
int main_PAT_A1085()
{
    int n,p;
    scanf("%d%d",&n,&p);
    int a[n];
    int i,j;
    for (i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    sort(a,a+n);
    int count=0;
    for (i=0; i<n; i++)
    {
       
        j=my_upper_bound(a,i+1,n-1,(long long)a[i]*p);
        if(j<=n&&((j-i)>count))
        {
            count=j-i;
        }
        
    }
    
    
    printf("%d\n",count);
    return 0;
}

int main_PAT_A1085_2()
{
    int n,p;
    scanf("%d%d",&n,&p);
    int a[n];
    int i,j;
    for (i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    sort(a,a+n);
    int count=0;
    i=0;
    j=1;
    while (i<n&&j<n&&i<j)
    {
        if (a[j]<=(long long)a[i]*p)
        {
            j++;
        }
        else
        {
            if((j-i)>count)
            {
                count=(j-i);
            }
            i++;
        }
    }
    if(j==n&&(j-i)>count)
    {
        count=(j-i);
    }
    
    
    printf("%d\n",count);
    return 0;
}
