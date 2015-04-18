//
//  LinkInsert.cpp
//  DataStructure
//  递增链表的插入 2-4 难度：简单
//  Created by zzh on 15/4/17.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "LinkInsert.h"
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    Node* next;
};

int main_LinkInsert()
{
    int n,m,i;
    bool IsInsert=false;
    scanf("%d%d",&n,&m);
    Node *head,*temp,*pre,*cur;
    head=(Node*)malloc(sizeof(Node));
    temp=NULL;
    pre=NULL ;
    cur=head;
    for (i=0; i<n; i++)
    {
        temp=(Node*)malloc(sizeof(Node));
        scanf("%d",&temp->data);
        temp->next=NULL;
        pre=cur;
        cur->next=temp;
        cur=temp;
        if(!IsInsert)
        {
            if(cur->data>=m)
            {
                temp=(Node*)malloc(sizeof(Node));
                temp->data=m;
                pre->next=temp;
                temp->next=cur;
                pre=temp;
                IsInsert=true;
            }
            
        }
    }
    while (head->next!=NULL)
    {
        printf("%d ",head->next->data);
        head=head->next;
    }
    
    return 0;
}
