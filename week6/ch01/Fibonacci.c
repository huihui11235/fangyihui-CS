#include<stdio.h>
int Fibonacci(int n)//����쳲���������
{
    int i,last,NextToLast,Answer;
    if(n<=1)
        return 1;
    Last=NextToLast=1;
    for(i=2;i<=n;i++)
    {
        Answer=Last+NextToLast;
        NextToLast=Last;
        Last=Answer;
    }
    return Answer;
}