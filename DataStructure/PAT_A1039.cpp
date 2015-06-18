//
//  PAT_A1039.cpp
//  DataStructure
//
//  Created by zzh on 15/6/16.
//  Copyright (c) 2015年 zzh. All rights reserved.
//  注意name要开5个，不然溢出，产生莫名其妙的错误

#include "PAT_A1039.h"
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int GetID(char *name)
{
    int id=0;
    for (int i=0; i<3; i++)
    {
        id=id*26+(name[i]-'A');
    }
    id=id*10+(name[3]-'0');
    return id;
}

int main_A1039()
{
    //int m=26*26*26*10+1;
    vector<int> SelectCourse[175761];
    int n,k;
    scanf("%d%d",&n,&k);
    int c ,s;
    for (int j=0; j<k; j++)
    {
        scanf("%d%d",&c,&s);
        int y;
        for (y=0; y<s; y++)
        {
            char name[5];
            scanf("%s",name);
            int id=GetID(name);
            SelectCourse[id].push_back(c);
        }
    }
    
    for (int i=0; i<n; i++)
    {
        char name[5];
        scanf("%s",name);
        printf("%s ",name);
        int id=GetID(name);
        printf("%lu",SelectCourse[id].size());
        sort(SelectCourse[id].begin(), SelectCourse[id].end());
        for (int x=0; x<SelectCourse[id].size(); x++)
        {
            printf(" %d",SelectCourse[id][x]);
        }
        printf("\n");
        
    }
    
    
    
    return 0;
}