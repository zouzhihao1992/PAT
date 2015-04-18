//
//  SimpleBankQueue.h
//  DataStructure
//
//  Created by zzh on 15/4/18.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#ifndef __DataStructure__SimpleBankQueue__
#define __DataStructure__SimpleBankQueue__

#define MaxQSize 1000
#define ERROR -1
#include <stdio.h>
struct Queue
{
    int Customer[MaxQSize];
    int front;
    int rear;
};
void InitialQ(Queue *Q);
bool IsEmpty(Queue *Q);
void AddQ(Queue *Q,int item);
int main_SimpleBankQueue();
int DeleteQ(Queue *Q);


#endif /* defined(__DataStructure__SimpleBankQueue__) */
