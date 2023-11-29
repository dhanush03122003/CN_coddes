#include<bits/stdc++.h>
using namespace std;
char flag;
vector<string> data;
vector<string> data1;
int flg_count=0;
void reciever(vector<string> data1)
{
    for(auto str:data1)
    {
        for(int i=1;i<=str.size()-2;i++)
        {
            if(str[i]!=flag)
            {
                cout<<str[i];
            }
            else
            {
                cout<<str[i];
                i++;
            }


        }
        cout<<endl;

    }
}
int main()
{
    int n;
    cout<<"data to be entered - ";
    cin>>n;
    string s;
    cout<<"flag - ";
    cin>>flag;
    while(n--)
    {
        cin>>s;
        data.push_back(s);
    }
    for (auto str : data)
    {
        string s1;
        s1+=flag;
        for(int i=0;i<=str.size()-1;i++)
        {
            if(str[i]!=flag)
            {
                s1+=str[i];
            }
            else
            {
                s1+=str[i];
                s1+=str[i];
            }
        }
        s1+=flag;
        data1.push_back(s1);
    }
    cout<<endl<<endl<<"encoded data"<<endl;
    for (auto i :data1)
    {
        cout<<i<<endl;

    }
     cout<<endl<<endl<<"reciever data"<<endl;
    reciever(data1);

}
