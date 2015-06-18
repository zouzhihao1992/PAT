//
//  PAT_A1022.cpp
//  DataStructure
//
//  Created by zzh on 15/6/18.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1022.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
void query(map<string, set<int> > &map,string &str)
{
    if(map.find(str)==map.end())
    {
        printf("Not Found\n");
        
    }
    else
    {
        for (set<int>::iterator it=map[str].begin(); it!=map[str].end();it++)
        {
            printf("%d\n",*it);
        }

    }
    
    
}
map<string,set<int>> mapTitle,mapAuthor,mapKeyWord,mapPublisher,mapYear;

int main_PAT_A1022()
{
    int id,n,m,type;
    string title,keyWord,author,publisher,year;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&id);
        getchar();
        getline(cin,title);
        mapTitle[title].insert(id);
        getline(cin,author);
        mapAuthor[author].insert(id);
        while(cin>>keyWord)
        {
            mapKeyWord[keyWord].insert(id);
            char c=getchar();
            if(c=='\n')
            {
                break;
            }
        }
        getline(cin,publisher);
        mapPublisher[publisher].insert(id);
        getline(cin,year);
        mapYear[year].insert(id);
    }
    scanf("%d",&m);
    string q;
    for(int j=0;j<m;j++)
    {
        scanf("%d",&type);
        getchar(); //干掉分号
        getchar();
        getline(cin,q);
        printf("%d: %s\n",type,q.c_str());
        switch (type)
        {
            case 1:
                query(mapTitle,q);
                break;
            case 2:
                query(mapAuthor,q);
                break;
            case 3:
                query(mapKeyWord,q);
                break;
            case 4:
                query(mapPublisher,q);
                break;
            case 5:
                query(mapYear,q);
                break;
                
            default:
                break;
        }
        
    }
    
    return 0;
}
