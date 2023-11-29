#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter the size : ";
    int n;
    cin>>n;
    int sen[n];
    for(int i=0;i<=n-1;i++)
    {
        cin>>sen[i];
    }
    cout<<"sent - "<<sen[0]<<endl;
    for(int i=1;i<=n-1;i++)
    {
        cout<<"ack-"<<sen[i]<<endl;
        cout<<"sent - "<<sen[i]<<endl;
    }
}
