#include <bits/stdc++.h>
using namespace std;
vector<string> status;
void ack_lost(int n, vector<int> &random_numbers_ack) {
    int count = 4;
    mt19937 gen(static_cast<unsigned int>(time(0))); // Seed with current time
    uniform_int_distribution<int> distribution(1, n - 1);
    for (int i = 0; i < count; i++) {
        int random_number = distribution(gen);
        random_numbers_ack.push_back(random_number);
    }
}
void display(int left,int right,int arr[])
{
    cout<<"present_Window"<<endl;
    for(int i=left;i<=right;i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl<<endl;
}
int main()
{
    cout<<"enter the size : ";
    int n;
    cin>>n;
    int sen[n];
    vector<int> random_numbers_ack;
    for(int i=0;i<=n-1;i++)
    {
        cin>>sen[i];
    }
    ack_lost(n,random_numbers_ack);
    int win_size  = 3;
    vector<int> window(win_size);
    int left = 0;
    int ack = 1;
    int right = win_size;
    string ss;
    for(int i =0;i<=win_size && i <=n-1;i++)
    {
        window.push_back(i);
    }
    for(int x : window)
    {
       display(left,right-1,sen);
       auto it = find(random_numbers_ack.begin(),random_numbers_ack.end(),ack);
       if(it != random_numbers_ack.end())
       {
           this_thread::sleep_for(std::chrono::seconds(3));
           cout<<"ACK : "<<sen[ack]<<" lost"<<endl;
           cout<<"sending window again"<<endl;
           display(left,right-1,sen);
       }
        left++;
        window.erase(window.begin());
        if(right>=n)
        {
            return 0;
        }
        else
        {
            window.push_back(right);
        }
        right++;
        ack++;
    }
}
