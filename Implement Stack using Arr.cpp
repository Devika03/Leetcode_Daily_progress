#include<iostream>
#include<cmath>
using namespace std;
//Implement stack using arrays.  
int arr[5];//cap. is 5. 
int top = -1;
void push(int x)
{
    arr[++top]=x;//First top is ++ and then x is placed.
}
void pop()
{
    top--;
}
int top()
{
    return arr[top];
}
int size()
{
    return top+1;
}
int isEmpty()
{
    return (top==-1);
}
 
