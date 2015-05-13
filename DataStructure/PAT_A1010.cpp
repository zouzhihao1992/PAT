//
//  PAT_A1010.cpp
//  DataStructure
//
//  Created by zzh on 15/5/9.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1010.h"
#include <stdio.h>
#include <string.h>
long long getNumber(char *a,long long radix)
{
    int len=strlen(a);
    int i;
    long long result=0;
    for (i=0; i<len; i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            result=result*radix+(a[i]-'0');
        }
        else if(a[i]>='a'&&a[i]<='z')
        {
            result=result*radix+(a[i]-'a'+10);
        }
    }
    return result;
}
int findMax(char *a)
{
    int len=strlen(a);
    int i,max=-1;
    for(i=0;i<len;i++)
    {
        int temp;
        if(a[i]>='0'&&a[i]<='9')
        {
            temp=(a[i]-'0');
        }
        else if(a[i]>='a'&&a[i]<='z')
        {
            temp=(a[i]-'a'+10);
        }
        if(temp>max)
        {
            max=temp;
        }
    }
    return max;
}
int main_PAT_A1010()
{
    char n1[11], n2[11];
    int tag,radix;
    scanf("%s %s %d %d",n1,n2,&tag,&radix);
    if(tag==2)
    {
        char temp[11];
        strcpy(temp, n1);
        strcpy(n1, n2);
        strcpy(n2, temp);
    }
    long long target=getNumber(n1, 10);
    long long left,right;
    left=findMax(n2)+1;
    right=target>left?target:left;
    long long mid=0;
    while(left<=right)
    {
        mid=(left+right)/2;
        long long temp=getNumber(n2, mid);
        if(temp>target)
        {
            right=mid-1;
        }
        else if(temp<target)
        {
            left=mid+1;
        }
        else if (temp==target)
        {
            break;
        }
    }
    
    if(left>right)
    {
        printf("Impossible");
    }
    else
    {
        printf("%lld\n",mid);
    }
    
    return 0;
}