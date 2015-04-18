//
//  SimpleBankQueue.cpp
//  DataStructure
//
//  Created by zzh on 15/4/18.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "SimpleBankQueue.h"
#include <stdio.h>
#include <stdlib.h>

int flag=0;

int main_SimpleBankQueue()
{
    int n,i;
    scanf("%d",&n);
    Queue *A=(Queue*)malloc(sizeof(Queue));
    Queue *B=(Queue*)malloc(sizeof(Queue));
    
    InitialQ(A);
    InitialQ(B);
    for (i=0; i<n; i++)
    {
        int temp;
        scanf("%d",&temp);
        if(temp%2==1)
        {
            AddQ(A, temp);
        }
        else
        {
            AddQ(B, temp);
        }
    }
    
    while(!IsEmpty(A)&&!IsEmpty(B))
    {
        if (!flag)
        {
            printf("%d",DeleteQ(A));
            flag=1;
        }
        else
        {
            printf(" %d",DeleteQ(B));
        }
        
        if (!IsEmpty(A))
        {
            printf(" %d",DeleteQ(A));
        }
        
        printf(" %d",DeleteQ(B));
        
    }
    
    while (!IsEmpty(A))
    {
        if (!flag)
        {
            printf("%d",DeleteQ(A));
            flag=1;
        }
        else
        {
            printf(" %d",DeleteQ(A));
        }
    }
    
    while (!IsEmpty(B))
    {
        if (!flag)
        {
            printf("%d",DeleteQ(B));
            flag=1;
        }
        else
        {
            printf(" %d",DeleteQ(B));
        }

    }
    
    printf("\n");
    
    return 0;
}
void InitialQ(Queue *Q)
{
    Q->rear=Q->front=0;
}

bool IsEmpty(Queue *Q)
{
    return Q->rear==Q->front;
}

void AddQ(Queue *Q,int item)
{
    if ((Q->rear+1)%MaxQSize==Q->front)
    {
        printf("队列满,无法插入");
        return;
    }
    Q->rear=(Q->rear+1)%MaxQSize;
    Q->Customer[Q->rear]=item;
}

int DeleteQ(Queue *Q)
{
    if (Q->rear==Q->front)
    {
        printf("队列空，无法删除");
        return ERROR;
    }
    Q->front=(Q->front+1)%MaxQSize;
    return Q->Customer[Q->front];
}


