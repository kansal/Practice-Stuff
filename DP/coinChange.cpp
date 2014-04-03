#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int change(vector <int> coins,int total,int size)
{
    /*Create two sets- first set that contain the atleast one coin and second no coin*/
    if(total==0)
    {
        for(int i=0;i<coins.size();i++)
            return 1;
    }
    else if(total<0)
        return 0;
    else if(size<=0 && total>=1)
        return 0;
    else
    {
        int sum=0;
        sum=change(coins,total-coins[size-1],size)+change(coins,total,size-1);//containing and not containing a particular coin.
        return sum;
    }
}
int main()
{
    vector <int> coins;
    int total;
    int numCoins,k;
    cin>>numCoins;
    cin>>total;
    for(int i=0;i<numCoins;i++)
    {
        cin>>k;
        coins.push_back(k);
    }
    cout<<change(coins,total,numCoins);
    return 0;
}
