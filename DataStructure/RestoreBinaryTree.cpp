//
//  RestoreBinaryTree.cpp
//  DataStructure
//
//  Created by zzh on 15/4/18.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include "RestoreBinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#define Max 50
TreeNode* CreateTree(char *pre,char *in,int len)
{
    if (len==0)  
    {
        return NULL;
    }
    TreeNode *T;
    T=(TreeNode*)malloc(sizeof(TreeNode));
    int i;
    T->data=pre[0];
    for (i=0; i<len; i++)
    {
        if(pre[0]==in[i])
        {
            break;
        }
    }
    T->left=CreateTree(pre+1, in, i);
    T->right=CreateTree(pre+i+1, in+i+1,len-i-1);
    return T;
}

int Height(TreeNode *T)
{
    int H,Left,Right;
    if(!T)
    {
        return 0;
    }
    Left=Height(T->left);
    Right=Height(T->right);
    H=(Left>Right)?Left:Right;
    ++H;
    
    return H;
}

int main_RestoreBinaryTree()
{
    char pre[Max];
    char in[Max];
    int len;
    scanf("%d",&len);
    scanf("%s",pre);
    scanf("%s",in);
    printf("%d",Height(CreateTree(pre, in, len)));
    return 0;
}
