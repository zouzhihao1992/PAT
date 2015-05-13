//
//  Arena_1934.cpp
//  DataStructure
//
//  Created by zzh on 15/5/9.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "Arena_1934.h"

#include <stdio.h>

int main_Arena_1934()
{
    int n,i;
    scanf("%d",&n);
    int data[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&data[i]);
    }
    int x;
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(data[i]==x)
        {
            printf("%d",i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}