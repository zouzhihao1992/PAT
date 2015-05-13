//
//  PAT_B1022.cpp
//  DataStructure
//
//  Created by zzh on 15/4/24.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_B1022.h"
#include <stdio.h>
int main_PAT_B1022()
{
    int A,B,D,sum;
    int result[1000];
    int count=0;
    scanf("%d%d%d",&A,&B,&D);
    sum=A+B;
    do
    {
        result[count++]=sum%D;
        sum=sum/D;
        
    }while(sum!=0);
    int i;
    for (i=count-1 ; i>=0; i--)
    {
        printf("%d",result[i]);
    }
    printf("\n");
    return 0;
}
