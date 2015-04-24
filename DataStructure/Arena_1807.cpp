//
//  Arena_1807.cpp
//  DataStructure
//
//  Created by zzh on 15/4/23.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "Arena_1807.h"
#include <stdio.h>
#include <string.h>

int main_arena_1807()
{
    char str[1000][1000];
    int count[1000];
    int max=0;
    int min=1000;
    int i=0,j;
    while(gets(str[i]))
    {
        
        count[i]=strlen(str[i]);
        if (strlen(str[i])>max)
        {
            max=strlen(str[i]);
        }
        if (strlen(str[i])<min)
        {
            min=strlen(str[i]);
        }
        
        i++;
    }
    
    for (j=0; j<=i; j++)
    {
        if ( min==count[j])
        {
            printf("%s\n",str[j]);
        }
    }
    
    for (j=0; j<=i; j++)
    {
        if ( max==count[j])
        {
            printf("%s\n",str[j]);
        }
    }
    return 0;
}