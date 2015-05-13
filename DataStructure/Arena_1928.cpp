//
//  Arena_1928.cpp
//  DataStructure
//
//  Created by zzh on 15/4/24.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "Arena_1928.h"
#include <stdio.h>
#include <math.h>
int leap(int year);
int days(int year,int month,int day);
int getResult(int yMin,int yMax);
int m[13][2]=
{
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};
int main_Arena_1928()
{
    int y1,m1,d1;
    int y2,m2,d2;
    int sum=0;
    while ( scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
    {
        
        scanf("%4d%2d%2d",&y2,&m2,&d2);
        if(y1>y2)
        {
            sum+=getResult(y2, y1);
            sum+=days(y1, m1, d1);
            sum-=days(y2, m2, d2);
        }
        else if(y1<y2)
        {
            sum+=getResult(y1, y2);
            sum+=days(y2, m2, d2);
            sum-=days(y1, m1, d1);
        }
        else if(y1==y2)
        {
            int temp1=days(y1,m1,d1);
            int temp2=days(y2,m2,d2);
            sum=temp1>=temp2?temp1-temp2:temp2-temp1;
        }
        sum++;
        printf("%d\n",sum);
        sum=0;
        
    }
        return 0;
}

int getResult(int yMin,int yMax)
{
    int i;
    int result=0;
    for(i=yMin;i<yMax;i++)
    {
        if(leap(i))
        {
            result+=366;
        }
        else
        {
            result+=365;
        }
    }
    return result;
}
int leap(int year)
{
    return (year%4==0&&year%100!=0)||(year%400==0);
}
    //计算该日期是本年的第几天
int days(int year,int month,int day)
{
    int i,j=0,days=0;
    if(leap(year))
    {
        j=1;
    }
    for(i=1;i<month;i++)
    {
        days+=m[i][j];
    }
    days+=day;
    return days;
}