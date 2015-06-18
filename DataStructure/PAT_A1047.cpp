//
//  PAT_A1047.cpp
//  DataStructure
//
//  Created by zzh on 15/6/16.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1047.h"
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;


char names[40010][5];
vector<int> cources[2510];

bool cmp2(int a,int b)
{
    return strcmp(names[a], names[b])<0;
}
int main_PAT_A1047()
{
    int n,k;
    scanf("%d%d",&n,&k);
    
    for (int i=0; i<n; i++)
    {
        int num;
        scanf("%s%d",names[i],&num);
        for (int j=0; j<num; j++)
        {
            int c;
            scanf("%d",&c);
            cources[c].push_back(i);
        }
    }
    for (int j=1; j<=k; j++)
    {
        printf("%d %lu\n",j,cources[j].size());
        sort(cources[j].begin(), cources[j].end(), cmp2);
        for(int m=0;m<cources[j].size();m++)
        {
            printf("%s\n",names[cources[j][m]]);
        }
        
    }
    
    return 0;
}



