#include <bits/stdc++.h>
using namespace std;
vector<string> status;
void ack_lost(int n, std::vector<int> &random_numbers_ack)
{
    int count = 4;
    std::mt19937 gen(static_cast<unsigned int>(std::time(0))); // Seed with current time
    std::uniform_int_distribution<int> distribution(0, n - 1);

    for (int i = 0; i < count; i++) {
        int random_number = distribution(gen);
        random_numbers_ack.push_back(random_number);
    }

}
void data_lost(int n, std::vector<int> &random_numbers_data) {
    int count = 4;
    std::mt19937 gen(static_cast<unsigned int>(std::time(0))); // Seed with current time
    std::uniform_int_distribution<int> distribution(0, n - 1);

    for (int i = 0; i < count; i++) {
        int random_number = distribution(gen);
        random_numbers_data.push_back(random_number);
    }

}
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

    vector<int> random_numbers_ack;
    vector<int> random_numbers_data;
    ack_lost(n,random_numbers_ack);
    ack_lost(n,random_numbers_data);
    cout<<"sent - "<<sen[0]<<endl;
    status.push_back("R"+to_string(sen[0]));
    for(int i =1;i<=n-1;i++)
    {
       int found=0;
       auto it = std::find(random_numbers_data.begin(), random_numbers_data.end(), i);
       auto it1 = std::find(random_numbers_ack.begin(), random_numbers_ack.end(), i);
       if (it != random_numbers_ack.end() || it1 != random_numbers_data.end())
        {
        found=1;
        }
        if(found==1)
        {
            this_thread::sleep_for(std::chrono::seconds(3));
            cout<<"ACK - "<<sen[i]<<" lost"<<endl;
            cout<<"paket sent again:"<<endl;
            status.push_back("R"+to_string(sen[i-1]));
            cout<<"dublicate - found : "<<endl;// discard dublicates
            cout<<"DISCRDED : "<<sen[i-1]<<endl;
            status.push_back("D"+to_string(sen[i-1]));
            cout<<"ACK - "<<sen[i]<<" recieved"<<endl;
            status.push_back("ACK"+to_string(sen[i]));
        }
        else
        {
            cout<<"ACK - "<<sen[i]<<" recieved"<<endl;
             status.push_back("ACK"+to_string(sen[i]));
        }
        cout<<"sent - "<<sen[i]<<endl;
        status.push_back("R"+to_string(sen[i]));
    }
    for(string i:status)
    {
        cout<<i<<"  ";// for printing the sequence of operations
    }
}
