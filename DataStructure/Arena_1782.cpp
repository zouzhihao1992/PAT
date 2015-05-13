//
//  Arena_1782.cpp
//  DataStructure
//
//  Created by zzh on 15/5/3.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "Arena_1782.h"
#include <stdio.h>

int main_Arena_1782()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int book[m+1];
    for (int j=0; j<=m+1; j++)
    {
        book[j]=0;
    }
    int person[n+1];
    int i;
    for (i=1; i<=n; i++)
    {
        int temp;
        scanf("%d",&temp);
        book[temp]++;
        person[i]=temp;
    }
    for (i=1; i<=n; i++)
    {
        if (book[person[i]]>1)
        {
            printf("%d\n",book[person[i]]-1);
        }
        else
        {
            printf("BeiJu\n");
        }
        
    
    }
    return 0;
}