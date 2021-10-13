#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int c=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
            a[c++]=a[i];
    }
    while(c<n)
        a[c++]=0;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
