#include<iostream>
#include<cmath>
using namespace std;

void pse(int a[])
{
    stack<integer>s;
    for(int i =0 ; i<a.length ; i++)
    {
        while(!s.empty())
        {
            if(s.top()>=a[i])
            {
                s.pop();
            }
        }
        if(s.empty())cout<<-1;//If(s.empty())
        else cout<<s.top();
        s.push(a[i]);//In the end , we push the ele.  
    }

}