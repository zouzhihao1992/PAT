//
//  Arena_1923.cpp
//  DataStructure
//
//  Created by zzh on 15/5/3.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "Arena_1923.h"
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main_Arena_1923()
{
    int n;
    int *a;
    while (scanf("%d",&n)!=EOF)
    {
        a=(int*)malloc(sizeof(int)*n);
        for (int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for (int j=0; j<n; j++)
        {
            printf("%d ",a[j]);
        }
        printf("\n");
    }
   
    return 0;
}