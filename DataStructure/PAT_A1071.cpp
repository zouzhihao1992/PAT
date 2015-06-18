//
//  PAT_A1071.cpp
//  DataStructure
//
//  Created by zzh on 15/6/18.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1071.h"

#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
using namespace std;
bool check(char a)
{
    if(a>='0'&&a<='9') return true;
    if (a>='a'&&a<='z') return true;
    if (a>='A'&&a<='Z') return true;
    return false;

}
int main_PAT_A1071()
{
    string str;
    map<string,int> count;
    getline(cin,str);
    int i=0;
    while(i!=str.length())
    {
        string temp;
        while(check(str[i]))
        {
           
            if(str[i]>='A'&&str[i]<='Z')
            {
                str[i]+=32;
            }
            temp+=str[i];
            i++;
        }
        if(count.find(temp)==count.end())
        {
            count[temp]=1;
        }
        else
        {
            count[temp]++;
        }
        temp.clear();
        while(!check(str[i])&&i<str.length())
        {
            i++;
        }
        
    }
    
    int max=0;
    string maxstr;
    for(map<string,int>::iterator it=count.begin();it!=count.end();it++)
    {
        if(it->second>max)
        {
            max=it->second;
            maxstr=it->first;
        }
    }
    
    printf("%s %d",maxstr.c_str(),max);
    
    
    return 0;
}