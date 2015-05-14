//
//  PAT_A1048.cpp
//  DataStructure
//
//  Created by zzh on 15/5/13.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1048.h"

#include <stdio.h>
#include <algorithm>
using namespace std;
int main_PAT_A1048_1()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    i=0;
    int j=n-1;
    while(i<j)
    {
        if(a[i]+a[j]==m)
        {
            printf("%d %d",a[i],a[j]);
            return 0;
        }
        else if(a[i]+a[j]<m)
        {
            i++;
        }
        else if(a[i]+a[j]>m)
        {
            j--;
        }
            
    }
    
    printf("No Solution");
    
    return 0;
}

int main_PAT_A1048_2()
{
    int n,m;
    int HashTable[1005]={0};
    scanf("%d%d",&n,&m);
    int i,a;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        ++HashTable[a];
    }
    for (i=0; i<m; i++)
    {
        if(HashTable[i]&&HashTable[m-i])
        {
            if(i==m-i&&HashTable[i]<=1)
            {
                continue;
            }
            printf("%d %d\n",i,m-i);
            return 0;
        }    }
    printf("No Solution");
    
    return 0;
}