//
//  main.cpp
//  Simple_Caculator
//  数据结构习题 2-1
//  Created by zzh on 15/4/14.
//  Copyright (c) 2015年 zzh. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
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


