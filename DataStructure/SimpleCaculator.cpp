//
//  SimpleCaculator.cpp
//  2-1  简单计算器 难度：简单
//  Created by zzh on 15/4/14.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include <stdio.h>
using namespace std;
int main_SimpleCaculator()
{
    int Sum,x;
    char op;
    scanf("%d%c",&Sum,&op);
    while (op!='=')
    {
        scanf("%d",&x);
        switch (op)
        {
            case '+':
                Sum+=x;
                break;
            case '-':
                Sum-=x;
                break;
            case '*':
                Sum*=x;
                break;
            case '/':
                if (x==0)
                {
                    printf("除法分母为零");
                    return 0;
                }
                else
                {
                    Sum/=x;
                }
                break;
            default:
                printf("非法输入");
                return 0;
        }
        scanf("%c",&op);
    }
    printf("%d",Sum);
    return 0;
    
}


