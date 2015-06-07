//
//  PAT_A1078.cpp
//  DataStructure
//
//  Created by zzh on 15/5/28.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1078.h"
#include <stdio.h>
#include <math.h>
bool isPrime_PAT_A1078(int n)
{
    if(n<2)
    {
        return false;
    }
    for (int i=2; i<=sqrt(n*1.0); i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    
    return true;
}
int near(int m)
{
    while(!isPrime_PAT_A1078(m))
    {
        m++;
    }
    return m;
}
int main_PAT_A1078()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int r=near(m);
    bool HashTable[r];
    int i,num;
    for(i=0;i<r;i++)
    {
        HashTable[i]=false;
    }
    for (i=0; i<n; i++)
    {
        scanf("%d",&num);
        if(!HashTable[num%r])
        {
            HashTable[num%r]=true;
            if(i==0)
            {
                printf("%d",num%r);
            }
            else
            {
               printf(" %d",num%r);
            }
            continue;
        }
        else
        {
            int step;
            for (step=1; step<r; step++)
            {
                if(!HashTable[(num+step*step)%r])
                {
                    HashTable[(num+step*step)%r]=true;
                    if(i==0)
                    {
                        printf("%d",(num+step*step)%r);
                    }
                    else
                    {
                        printf(" %d",(num+step*step)%r);
                    }

                    break;
                }
            }
            
            if (step==r)
            {
                if(i==0)
                {
                    printf("-");
                }
                else
                {
                    printf(" -");
                }

            }
        }
        
    }
    
    
    
    return 0;
}











