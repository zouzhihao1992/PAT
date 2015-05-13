//
//  PAT_B1023.cpp
//  DataStructure
//
//  Created by zzh on 15/4/25.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_B1023.h"
#include <stdio.h>

int main_PAT_B1023()
{
    int a[10];
    int i;
    for (i=0; i<10; i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=1; i<=9; i++)
    {
        if(a[i]!=0)
        {
            printf("%d",i);
            --a[i];
            break;
        }
    }
    for(i=0;i<a[0];i++)
    {
        printf("0");
    }
    for(i=1;i<=9;i++)
    {
        int j;
        for (j=0; j<a[i]; j++)
        {
            printf("%d",i);
        }
    }
    return 0;
}