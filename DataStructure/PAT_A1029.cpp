//
//  PAT_A1029.cpp
//  DataStructure
//
//  Created by zzh on 15/5/13.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1029.h"

#include "stdio.h"

int main_PAT_A1029()
{
    int n1,n2;
    scanf("%d",&n1);
    int a[n1];
    int i,j;
    for(i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }
    
    scanf("%d",&n2);
    int b[n2];
    for(i=0;i<n2;i++)
    {
        scanf("%d",&b[i]);
    }
    int mid=(n1+n2-1)/2;
    i=0,j=0;
    int count=-1;
    while(i<n1&&j<n2)
    {
        if (a[i]<b[j])
        {
            count++;
            
            if (count==mid)
            {
                printf("%d",a[i]);
                break;
            }
            i++;
        }
        else
        {
            count++;
            
            if (count==mid)
            {
                printf("%d",b[j]);
                break;
            }

            j++;
        }
    }
    
    while(i<n1)
    {
        count++;
        
        if (count==mid)
        {
            printf("%d",a[i]);
            break;
        }
        i++;
    }
    while(j<n2)
    {
        count++;
        
        if (count==mid)
        {
            printf("%d",b[j]);
            break;
        }
        j++;
    }
    
    return 0;
}
int main_PAT_A1029_2()
{
    int max=0x7fffffff;
    int n1,n2;
    scanf("%d",&n1);
    int a[n1+1];
    int i,j;
    for(i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }
    a[n1]=max;
    scanf("%d",&n2);
    int b[n2+1];
    for(i=0;i<n2;i++)
    {
        scanf("%d",&b[i]);
    }
    b[n2]=max;
    int mid=(n1+n2-1)/2;
    int count=0;
    i=0;
    j=0;
    while(count<mid)
    {
        if(a[i]<b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
        count++;
        
    }
    
    if(a[i]<b[j])
    {
        printf("%d",a[i]);
    }
    else
    {
        printf("%d",b[j]);
    }
    
    return 0;
}






