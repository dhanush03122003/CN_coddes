#include<bits/stdc++.h>
using namespace std;
int cal_red_bits(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(pow(2, i)>=i+n+1)
        {
            return i;
        }
    }
}
string cal_parity_bit(string s,int n)
{
    int maxNumbers = s.length();
    for(int k=1;k<=n;k++)
    {
       int num_zeroes=0;
    for (int i = 1; i <= maxNumbers; i++)
    {
        int shifted = i >> (k - 1); // Shift the number to the right to check the desired bit
        if (shifted % 2 == 1)
        { // Check if the bit at the specified position from the right is 1

            std::bitset<32> binary(i); // Convert the number to binary
            if(s[i-1]=='1')
            {
                num_zeroes++;
            }
        }
    }
    if(num_zeroes%2==0)
    {
        s[k-1] = '0';
    }
    else
    {
        s[k-1] = '1';
    }
    }
return string(s.rbegin(), s.rend());

}
void recirver_side(int n)
{

    string rec,s2;
    //cin>>rec;
    rec = "0010010";
    cout<<"reciever side : "<<rec<<endl;
    string s = string(rec.rbegin(), rec.rend());
    int maxNumbers = s.length();
    for(int k=1;k<=n;k++)
    {
       int num_zeroes=0;
    for (int i = 1; i <= maxNumbers; i++)
    {
        int shifted = i >> (k - 1); // Shift the number to the right to check the desired bit
        if (shifted % 2 == 1)
        { // Check if the bit at the specified position from the right is 1

            std::bitset<32> binary(i); // Convert the number to binary
            if(s[i-1]=='1')
            {
                num_zeroes++;
            }
        }
    }
  if(num_zeroes%2==0)
    {
        s2+= '0';
    }
    else
    {
        s2+= '1';
    }
    }

    cout<<"reciever side parity bits : "<<string(s2.rbegin(), s2.rend());



}
int main()
{
    string input;

    //cin>>input;

    input = "1010";
    cout<<"input : "<<input<<endl;

    int n_red  = cal_red_bits(input.length());
    string s = string(input.rbegin(), input.rend());
    for(int i=0;i<=n_red-1;i++)
    {
        s.insert(pow(2,i)-1, 1, '0');
    }
    string modified = string(s.rbegin(), s.rend());
    cout<<"modified : "<< cal_parity_bit(s,n_red) <<endl;
    recirver_side(n_red);
    return 0;
}
