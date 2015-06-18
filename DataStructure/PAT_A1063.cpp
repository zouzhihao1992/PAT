//
//  PAT_A1063.cpp
//  DataStructure
//
//  Created by zzh on 15/6/16.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1063.h"

#include <stdio.h>
#include <set>
using namespace std;
set<int> nums[51];
void compare(int a,int b)
{
    int total=(int)nums[b].size();
    int same=0;
    for (set<int>::iterator it=nums[a].begin(); it!=nums[a].end(); it++)
    {
        if(nums[b].find(*it)!=nums[b].end())
        {
            same++;
        }
        else
        {
            total++;
        }
    }
    printf("%.1f%%\n",same*100.0/total);
}
int main_PAT_A1063()
{
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        int m=0;
        scanf("%d",&m);
        for (int j=0; j<m; j++)
        {
            int temp;
            scanf("%d",&temp);
            nums[i+1].insert(temp);
        }
    }
    int a,b;
    int times;
    scanf("%d",&times);
    for(int k=0;k<times;k++)
    {
        scanf("%d%d",&a,&b);
        compare(a, b);
    }
    return 0;
}