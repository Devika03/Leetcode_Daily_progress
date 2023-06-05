#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int nge[n], stack<int>st;
    for(int i =0 ; i<=2n-1 ; i++)
    {
        while(!st.empty() && st.top() <= a[i%n] )//For circular array qn., we use i%n .
        st.pop();
        if(i<n)
        {
            if(st.empty()==false)
            nge[i]=st.top();
            else nge[i]=-1;
        }
        st.push(a[i%n]);
    }
}