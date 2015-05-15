//
//  PAT_A1008.cpp
//  DataStructure
//
//  Created by zzh on 15/5/15.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1008.h"
#include <stdio.h>

int main_PAT_A1008()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int pre=0;
    int sum=0;
    for (i=0; i<n; i++)
    {
        if(a[i]>pre)
        {
            sum=sum+(a[i]-pre)*6+5;
        }
        else
        {
            sum=sum+(pre-a[i])*4+5;
        }
        pre=a[i];
    }
    
    printf("%d",sum);
    return 0;
    
}