//
//  PAT_A1060.cpp
//  DataStructure
//
//  Created by zzh on 15/6/17.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1060.h"

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int n;

string deal(string str,int &e)
{
    int k=0;
    while(str[0]=='0'&&str.length()>0)
    {
        str.erase(str.begin());
    }
    if(str[0]=='.')
    {
        str.erase(str.begin());
        while(str[0]=='0')
        {
            str.erase(str.begin());
            e--;
        }
    }
    else
    {
        while(k<str.length()&&str[k]!='.')
        {
            e++;
            k++;
        }
        if(str[k]=='.')
        {
            str.erase(str.begin()+(k));
        }
    }
    
    if(str.length()==0)
    {
        e=0;
    }
    
    string result;
    for(int i=0;i<n;i++)
    {
        if(i<str.length())
        {
            result+=str[i];
        }
        else
        {
            result+='0';
        }
    }
    
    return result;
}

int main_PAT_A1060()
{
   /* string test;
    int e=0;
    cin>>n>>test;
    printf("%s %d\n",deal(test, e).c_str(),e);
    printf("%d",e);
    */
   string str1,str2;
    
     cin>>n>>str1>>str2;
    
    int e1=0,e2=0;
    str1=deal(str1,e1);
    str2=deal(str2, e2);
    if(str1==str2&&e1==e2)
    {
        printf("YES 0.%s*10^%d",str1.c_str(),e1);
    }
    else
    {
        printf("NO 0.%s*10^%d 0.%s*10^%d",str1.c_str(),e1,str2.c_str(),e2);
    }
    

    
    return 0;
}