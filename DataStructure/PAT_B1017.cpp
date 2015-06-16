//
//  PAT_B1017.cpp
//  DataStructure
//
//  Created by zzh on 15/6/15.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_B1017.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
struct bign
{
    int d[1000];
    int len;
    bign()
    {
        memset(d,0,sizeof(d));
        len=0;
    }
    
};
bign Str2Num(char *str)
{
    bign a;
    a.len=(int)strlen(str);
    for (int i=0; i<a.len; i++)
    {
        a.d[i]=str[a.len-1-i]-'0';
    }
    return a;
}

int compare(bign a,bign b)
{
    if (a.len>b.len)
    {
        return 1;
    }
    else if (a.len<b.len)
    {
        return -1;
    }
    else
    {
        for (int i=0;i<a.len; i++)
        {
            if (a.d[i]<b.d[i])
            {
                return -1;
            }
            else if(a.d[i]>b.d[i])
            {
                return 1;
            }
        }
        
        return 0;
    }
}

bign add(bign a,bign b)
{
    int carray=0;
    bign result;
    for (int i=0; i<a.len||i<b.len; i++)
    {
        int temp=a.d[i]+b.d[i]+carray;
        result.d[result.len++]=temp%10;
        carray=temp/10;
    }
    if (carray!=0)
    {
        result.d[result.len++]=carray;
    }
    return result;
}
bign subn(bign a,bign b)
{
    bign result;
    for (int i=0; i<a.len||i<b.len; i++)
    {
        if (a.d[i]<b.d[i])
        {
            a.d[i+1]--;
            a.d[i]+=10;
        }
        result.d[result.len++]=a.d[i]-b.d[i];
    }
    while (result.len>1&&result.d[result.len-1]==0)
    {
        result.len--;
    }
    return result;
}

bign multi(bign a,int b)
{
    bign result;
    int carray=0;
    for (int i=0; i<a.len; i++)
    {
        int temp=a.d[i]*b+carray;
        result.d[result.len++]=temp%10;
        carray=temp/10;
    }
    while(carray!=0)
    {
        result.d[result.len++]=carray%10;
        carray/=10;
    }
    return result;
}
bign divide(bign a,int b,int &c)
{
    int carray=0;
    bign result;
    result.len=a.len;
    for (int i=a.len-1; i>=0; i--)
    {
        carray=carray*10+a.d[i];
        if(carray<b)
        {
            result.d[i]=0;
        }
        else
        {
            result.d[i]=carray/b;
            carray=carray%b;
        }
    }
    c=carray;
    while(result.len>1&&result.d[result.len-1]==0)
    {
        result.len--;
    }
    return result;
}

int main_PAT_B1017()
{
    char str[1000];
    int b;
    scanf("%s",str);
    scanf("%d",&b);
    bign result;
    int c;
    result=divide(Str2Num(str), b,c);
    for (int i=result.len-1; i>=0; i--)
    {
        printf("%d",result.d[i]);
    }
    printf(" %d",c);
    return 0;
}
