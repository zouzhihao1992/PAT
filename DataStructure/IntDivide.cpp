//
//  IntDivide.cpp
//  整数分解为若干项之和 2-3
//  Created by zzh on 15/4/15.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "IntDivide.h"
#include <stdio.h>
#include <string.h>
void Divide(int remainer,int start,char *term);
int Count;
int MaxSize=64;
int main_IntDivide()
{
    int n=4;
    Count=0;
    scanf("%d",&n);
    char term[MaxSize];
    sprintf(term, "%d=",n);
    //printf(term);
   
    Divide(n, 1, term);
    return 0;
}

void Divide(int remainer,int start,char *term)
{
    char temp[MaxSize];
    strcpy(temp,term);
    int i;
    for (i=start; i<=remainer; i++)
    {
        if(remainer-i>=i)
        {
            sprintf(temp+strlen(term), "%d+",i);
            Divide(remainer-i, i, temp);
        }
        else if(remainer-i==0)
        {
            sprintf(temp+strlen(term), "%d",i);
            Count++;
            if (Count%4!=1)
            {
                printf(";");
            }
            printf(temp);
            if (Count%4==0)
            {
                printf("\n");
            }
            
        }
    }
}