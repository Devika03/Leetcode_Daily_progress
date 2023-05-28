#include<iostream>
#include<cmath>
using namespace std;
//Implement stack using arrays.  
int arr[5];//cap. is 5. 
int front =0;
int rear =0;
int ct=0;
void push(int x)
{
    if(ct==max_cap) return -1;
    arr[rear%n]=x;
    rear++;ct++;
}
void pop()
{
    if(ct==0)return;//Stating no eles. in queue. 
    a[front%max_cap]=-1;//Some dummy no. 
    front++;ct--;
}
int top()
{
    if(ct==0) return -1;
    return arr[front%max_cap];
}
int size()
{
    return ct;
}
bool isEmpty()
{
    return (ct==0);
}