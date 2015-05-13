//
//  PAT_A1044.cpp
//  DataStructure
//
//  Created by zzh on 15/5/10.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1044.h"
#include <stdio.h>
int lower_bound(int a[],int n,int x)
{
    int left=1,right=n+1;
    int mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(a[mid]>=x)
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
int main_PAT_A1044()
{
    int n,m;
    int nearm=1000000;
    scanf("%d%d",&n,&m);
    int sum[n+2];
    int i,j;
    sum[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&sum[i]);
        sum[i]=sum[i]+sum[i-1];
    }
    for(i=1;i<=n;i++)
    {
        j=lower_bound(sum, n, sum[i-1]+m);
        if (j<=n&&sum[j]==sum[i-1]+m)
        {
            nearm=m;
            break;
        }
        else
        {
           if( j<=n&&nearm>(sum[j]-sum[i-1]))
           {
               nearm=sum[j]-sum[i-1];
           }
        }
    }
    
    for(i=1;i<=n;i++)
    {
        j=lower_bound(sum, n, sum[i-1]+nearm);
        if(j<=n&&(sum[j]-sum[i-1]==nearm))
        {
            printf("%d-%d\n",i,j);
        }
        
    }
    
    return 0;
}
