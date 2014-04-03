#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector <int>w;
vector <int>v;
int knapsack(int n, int weight)
{
    if(n==0 || weight==0)
        return 0;
    if(w[n] > weight)
        return knapsack(n-1,weight);
    else
        return max(v[n]+knapsack(n-1,weight-w[n]),knapsack(n-1,weight));
}

int main()
{
    int n,weight,val;
    cin>>n>>weight;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        v.push_back(val);
    }
    for(int i=0;i<n;i++)
    {
        cin>>val;
        w.push_back(val);
    }
    cout<< knapsack(n-1,weight);
    return 0;
}

