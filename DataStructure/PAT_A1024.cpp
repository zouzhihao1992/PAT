//
//  PAT_A1024.cpp
//  DataStructure
//
//  Created by zzh on 15/6/15.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1024.h"
#include <stdio.h>
#include <memory.h>
struct bign3
{
    int d[1000];
    int len;
    bign3()
    {
        memset(d,0,sizeof(d));
        len=0;
    }
    
};
bign3 StrToNum3(char *str)
{
    bign3 r;
    r.len=(int)strlen(str);
    for (int i=r.len-1; i>=0; i--)
    {
        r.d[i]=str[r.len-1-i]-'0';
    }
    return r;
}
bign3 add3(bign3 a,bign3 b)
{
    int carray=0;
    bign3 result;
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


bign3 reverse3(bign3 a)
{
    bign3 r;
    r.len=a.len;
    for (int i=0; i<r.len; i++)
    {
        r.d[i]=a.d[r.len-1-i];
    }
    return r;
}
bool ishw(bign3 a)
{
    for (int i=0; i<=a.len/2; i++)
    {
        if (a.d[i]!=a.d[a.len-i-1])
        {
            return false;
        }
    }
    return true;
}
int main_PAT_A1024()
{
    char str[10];
    int k;
    scanf("%s",str);
    scanf("%d",&k);
    bign3 a=StrToNum3(str);
    int i;
    for (i=0; i<k; i++)
    {
        if(ishw(a))
        {
            break;
        }
        a=add3(a, reverse3(a)) ;
    }
    for (int j=a.len-1; j>=0; j--)
    {
        printf("%d",a.d[j]);
    }
    
    printf("\n");
    if (i==0)
    {
        printf("0");
    }
       else
    {
        printf("%d",i);
    }
    
    return 0;
}