//
//  PAT_A1025.cpp
//  DataStructure
//  http://www.patest.cn/contests/pat-a-practise/1025
//  Created by zzh on 15/4/24.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1025.h"
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct student
{
    char regist_number[13];
    int final_rank;
    int location_number;
    int local_rank;
    int grade;
};
bool cmp(student a,student b);
int main_PAT_A1025()
{
    int N,K;
    int sum=0;
    scanf("%d",&N);
   
    student students[N][30];
    student result[3000];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&K);
        
        int j;
        for (j=0; j<K; j++)
        {
            scanf("%s %d",students[i][j].regist_number,&students[i][j].grade);
            students[i][j].location_number=i+1;
        }
        sort(&students[i][0],&students[i][K],cmp);
        students[i][0].local_rank=1;
        for (j=1; j<K; j++)
        {
            
            if (students[i][j].grade==students[i][j-1].grade)
            {
                students[i][j].local_rank=students[i][j-1].local_rank;
            }
            else
            {
                students[i][j].local_rank=j+1;
            }
            
        }
        int temp=sum;
        for (j=0; j<K; j++)
        {
            //printf("%s %d\n",students[i][j].regist_number,students[i][j].grade);
            result[temp]=students[i][j];
            temp++;
        }
        sum+=K;
    }
    sort(result,result+sum,cmp);
    result[0].final_rank=1;
    for (int m=1; m<sum; m++)
    {
        if (result[m].grade==result[m-1].grade)
        {
            result[m].final_rank=result[m-1].final_rank;
        }
        else
        {
            result[m].final_rank=m+1;
        }
    }
    printf("%d\n",sum);
    for (int n=0; n<sum; n++)
    {
        printf("%s %d %d %d\n",result[n].regist_number,result[n].final_rank,result[n].location_number,result[n].local_rank);
    }

    return 0;
}

bool cmp(student a,student b)
{
    if(a.grade!=b.grade)
    {
        return a.grade>b.grade;
    }
    else
    {
        return strcmp(a.regist_number, b.regist_number)<0;
    }
}

