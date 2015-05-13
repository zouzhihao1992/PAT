//
//  Arena_1924.cpp
//  DataStructure
//
//  Created by zzh on 15/5/3.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "Arena_1924.h"
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Student
{
    char name[101];
    int age;
    int grade;
};
bool cmp(Student a,Student b)
{
    if(a.grade!=b.grade)
    {
        return a.grade<b.grade;
    }
    else if(strcmp(a.name, b.name)!=0)
    {
        return strcmp(a.name, b.name)<0;
    }
    else
    {
        return a.age<b.age;
    }
}
int main_Arena_1924()
{
    int n;
    scanf("%d",&n);
    Student students[n];
    for (int i=0; i<n; i++)
    {
        scanf("%s%d%d",students[i].name,&students[i].age,&students[i].grade);
    }
    sort(students,students+n,cmp);
    for (int j=0; j<n; j++)
    {
        printf("%s %d %d\n",students[j].name,students[j].age,students[j].grade);
    }
    return 0;
}