//
//  Arena_1806.cpp
//  DataStructure
//
//  Created by zzh on 15/4/24.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "Arena_1806.h"
#include <stdio.h>
#include <string.h>
int main_Arena_1806()
{
    char temp[1000];
    while (gets(temp))
    {
        int len=strlen(temp);
        int i;
        int flag=1;
        for(i=0;i<len/2;i++)
        {
            if(temp[i]!=temp[len-1-i])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            printf("Yes!");
        }
        else
        {
            printf("No!");
        }
    }
    return 0;
}