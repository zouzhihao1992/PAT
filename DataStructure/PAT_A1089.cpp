//
//  PAT_A1089.cpp
//  DataStructure
//
//  Created by zzh on 15/5/12.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "PAT_A1089.h"
#include <stdio.h>

bool InsertSort(int *a,int *b,int n)
{
    
    int i,j,m;
    int temp;
    bool flag=true;
    for (i=1; i<n; i++)
    {
        flag=true;
        if(i!=1)
        {
            for(m=0; m<n; m++)
            {
                if (a[m]!=b[m])
                {
                    flag=false;
                    break;
                }
            }
        }
        temp=a[i];
        for (j=i-1; j>=0; j--)
        {
            if (a[j]>temp)
            {
                a[j+1]=a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1]=temp;
        
        if(i!=1&&flag==true)
        {
            printf("Insertion Sort\n");
            for (m=0; m<n; m++)
            {
                if(m==n-1)
                {
                    printf("%d",a[m]);
                }
                else
                {
                    printf("%d ",a[m]);
                }

            }
            return true;
        }
        
    }
    return false;
}
void merge(int *a,int l1,int r1,int l2,int r2)
{
    int i=l1,j=l2;
    int temp[r2-l1+1];
    int index=0;
    while(i<=r1&&j<=r2)
    {
        if(a[i]<=a[j])
        {
            temp[index++]=a[i++];
        }
        else
        {
            temp[index++]=a[j++];
        }
    }
    while(i<=r1)
    {
        temp[index++]=a[i++];
    }
    while(j<=r2)
    {
        temp[index++]=a[j++];
    }
    for(int m=0;m<index;m++)
    {
        a[l1+m]=temp[m];
    }
}
void MergeSort(int *a,int *b,int n)
{
   
    int step;
    bool flag=true;
    for (step=2; step/2<=n; step*=2)
    {
        if (step!=2)
        {
            flag=true;
            for(int i=0;i<n;i++)
            {
                if(a[i]!=b[i])
                {
                    flag=false;
                    break;
                }
            }
        }
        int i;
        for (i=0; i<n; i=i+step)
        {
            int mid=i+step/2-1;
            if(mid+1<n)
            {
                int right=(n-1)<(i+step-1)?(n-1):(i+step-1);
                merge(a, i, mid, mid+1, right);
            }
        }
        
        if (step!=2&&flag)
        {
            printf("Merge Sort\n");
            for(i=0;i<n;i++)
            {
                
                if(i==n-1)
                {
                    printf("%d",a[i]);
                }
                else
                {
                    printf("%d ",a[i]);
                }
            }
            return;
        }
    }
    
}

int main_PAT_A1089()
{
    int n,i;
    scanf("%d",&n);
    int a[n],b[n];
    int a1[n];
    for (i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        a1[i]=a[i];
    }
    
    for (i=0; i<n; i++)
    {
        scanf("%d",&b[i]);
    }
    
   if(!InsertSort(a,b,n))
   {
       MergeSort(a1, b, n);
   }
    return 0;
}

