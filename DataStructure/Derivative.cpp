//
//  Derivative.cpp
//  DataStructure
//  一元多项式求导 3-1 难度：简单
//  Created by zzh on 15/4/17.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "Derivative.h"
#include <stdlib.h>
struct PolyNode
{
    int coef;
    int expon;
    PolyNode *next;
};

int main_Derivative()
{
    int c,e;
    PolyNode *temp;
    PolyNode *head;
    PolyNode *cur;
    PolyNode *pre;
    temp=NULL;
    head=(PolyNode*)malloc(sizeof(PolyNode));
    cur=head;
    pre=head;
    while (scanf("%d%d",&c,&e)!=EOF)
    {
        if (c==-1000) //结束标志
        {
            break;
        }
        temp=(PolyNode*)malloc(sizeof(PolyNode));
        if(e==0)
        {
            if (cur==head)
            {
                temp->coef=0;
                temp->expon=0;
            }
            else
            {
                break;
            }
        }
        else
        {
            temp->coef=c*e;
            temp->expon=e-1;
        }
        temp->next=NULL;
        pre=cur;
        cur->next=temp;
        cur=temp;
    }
    
    while(head->next!=NULL)
    {
        printf("%d %d ",head->next->coef,head->next->expon);
        head=head->next;
    }
    
    return 0;
}
