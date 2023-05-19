//Print all the duplicates in the input string
//Use frequency map (It returns freq. + bool) or Sort (It only returns bool ).
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char string[100];
    cout<<"Enter string";
    cin.getline(string,80);
    cout<<"Duplicate characters:";
    for(int i = 0;i<strlen(string);i++)
    {
        for(int j = i+1 ; j<strlen(string);j++)
        {
            if(string[i]==string[j])
            {
                cout<<string[i]<<endl;
                break;
            }
        }
    }
    return 0;
}