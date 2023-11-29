#include<bits/stdc++.h>
using namespace std;
string xorStrings(string str1, string str2);
void add_red(string &data,int n)
{
    for(int i=1;i<=n;i++)
    {
        data+="0";
    }
}

string sender(string data,string divisor)
{
    int curr = divisor.size();
    string rem;
    for(int i=1;i<=divisor.size()-1;i++)
    {
        string x;
        if(i==1)
        {
          for(int j=0;j<=divisor.size()-1;j++)
         {
            x+=data[j];
         }
         rem = xorStrings(x,divisor);

        }
        x=rem;

        x = x.substr(1);
        x+=data[curr];
        curr++;
        rem = xorStrings(x,divisor);    }
    rem = rem.substr(1);
    return rem;


}
string xorStrings(string str1, string str2)
{
    cout<<"\ndoing xor of "<<str1<<"   "<<str2<<"   ";
    string result = "";
    for(int i = 0; i < str1.length(); ++i)
    {
        if(str1[i] != str2[i])
        {
            result+="1";
        }
        else
        {
            result+="0";
        }
    }
    cout<<"result:"<<result<<endl;
    return result;
}
int main()
{
    string data;
    string divisor;
    cin>>data;
    cin>>divisor;
    string data1=data;
    int len_R = divisor.size()-1;
    add_red(data, len_R);
    int curr = divisor.size();
    string rem;
    for(int i=1;i<=divisor.size()-1;i++)
    {
        string x;
        if(i==1)
        {
          for(int j=0;j<=divisor.size()-1;j++)
         {
            x+=data[j];
         }
         rem = xorStrings(x,divisor);

        }
        x=rem;

        x = x.substr(1);
        x+=data[curr];
        curr++;
        rem = xorStrings(x,divisor);
        cout<<rem<<endl;
    }
    rem = rem.substr(1);
    data1+=rem;
    cout<<endl<<endl<<"sender side remainder: "<<rem;


    cout<<"\nreciever side remainder"<<sender(data1,divisor)<<endl;

}
