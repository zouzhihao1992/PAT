//
//  PAT_A1023.cpp
//  DataStructure
//
//  Created by zzh on 15/6/15.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1023.h"
#include <stdio.h>
#include <memory.h>
int count2[20];
struct bign2
{
    int len;
    int d[20];
    bign2()
    {
        memset(d,0,sizeof(d));
        len=0;
    }
};
bign2 StrToNum2(char *str)
{
    bign2 r;
    r.len=(int)strlen(str);
    for (int i=r.len-1; i>=0; i--)
    {
        r.d[i]=str[r.len-1-i]-'0';
    }
    return r;
}
bign2 multi2(bign2 a,int b)
{
    bign2 r;
    int c=0;
    for (int i=0; i<a.len; i++)
    {
        int temp=a.d[i]*b+c;
        r.d[r.len++]=temp%10;
        c=temp/10;
    }
    while (c!=0)
    {
        r.d[r.len++]=c%10;
        c=c/10;
    }
    return r;
}

int main_PAT_A1023()
{
    memset(count2, 0, sizeof(count2));
    char a[20];
    scanf("%s",a);
    bign2 temp=StrToNum2(a);
    int i;
    for (i=0; i<temp.len; i++)
    {
        count2[temp.d[i]]++;
    }
    temp=multi2(temp, 2);
    for (i=0; i<temp.len; i++)
    {
        count2[temp.d[i]]--;
    }

    for (i=0; i<20; i++)
    {
        if(count2[i]!=0)
        {
            printf("No\n");
            for (int j=temp.len-1; j>=0; j--)
            {
                printf("%d",temp.d[j]);
            }
            return 0;

        }
    }
    printf("Yes\n");
    for (int j=temp.len-1; j>=0; j--)
    {
        printf("%d",temp.d[j]);
    }
    return 0;
}