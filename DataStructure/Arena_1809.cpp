
//
//  Arena_1809.cpp
//  DataStructure
//  http://arena.acmclub.com/problem.php?id=1809
//  Created by zzh on 15/4/24.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "Arena_1809.h"
#include <stdio.h>
#include <string.h>
int main_Arena_1809()
{
    char temp[1000];
    while (scanf("%s",temp)!=EOF)
    {
        int len=strlen(temp);
        if(temp[len-1]=='.')
        {
            printf("%d ",len-1);
        }
        else
        {
            printf("%d ",len);
        }
    }
    return 0;
}