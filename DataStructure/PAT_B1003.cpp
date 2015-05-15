//
//  PAT_B1003.cpp
//  DataStructure
//
//  Created by zzh on 15/5/14.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_B1003.h"
/*************************************************************************
 > File Name: PAT_B1003.cpp
 > Author: zouzhihao
 > Mail: zouzhihao_1992@163.com
 > Created Time: 2015-05-14 19:41
 ************************************************************************/
#include <stdio.h>
#include <string.h>

int main_PAT_B1003()
{
    int n;
    char str[101];
    
    scanf("%d",&n);
    while(n--)
    {
        int x=-1,y=-1,z=-1;
        int p=0,t=0,o=0;
        scanf("%s",str);
        int len=strlen(str);
        for(int i=0;i<len;i++)
        {
            if(str[i]=='P')
            {
                p++;
                x=i;
            }
            else if(str[i]=='T')
            {
                t++;
                y=i;
                
            }
            else if(str[i]!='A')
            {
                o++;
            }
        }
        
        z=len-(y+1);
        y=y-x-1;
        
        if(p==1&&t==1&&o==0&&z-(y-1)*x==x&&x*y-(z-x)==x&&y>0)
        {
           
                printf("YES\n");
                continue;
        }
        else
        {
            printf("NO\n");

        }
    }
        return 0;
    
}
