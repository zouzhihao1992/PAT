//
//  PAT_A1054.cpp
//  DataStructure
//
//  Created by zzh on 15/6/18.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1054.h"
#include <stdio.h>
#include <map>

using namespace std;

int main_PAT_A1054()
{
    int m,n;
    map<int, int> count;
    scanf("%d%d",&m,&n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            int temp;
            scanf("%d",&temp);
            if(count.find(temp)!=count.end())
            {
                count[temp]++;
            }
            else
            {
                count[temp]=1;
            }
        }
    }
    int max=0;
    int num=0;
    
    for (map<int,int>::iterator it=count.begin(); it!=count.end(); it++)
    {
        if (it->second>max)
        {
            num=it->first;
            max=it->second;
        }
    }
    printf("%d",num);
    return 0;
}