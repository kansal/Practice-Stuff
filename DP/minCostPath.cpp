#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;
vector <vector<int> > Mat(1000,vector<int>(1000,-1));
vector <vector<int> > table(1000,vector<int>(1000,-1));

int minCost(int n,int m)
{
    if(n==0 && m==0)
        return Mat[0][0];
    if(table[n][m]== -1)
    {
        int temp;
        if(n==0)
            temp=minCost(n,m-1);
        else if(m==0)
            temp=minCost(n-1,m);
        else
        {
            temp=min(minCost(n-1,m-1),minCost(n-1,m));
            temp=min(temp,minCost(n,m-1));
        }
        table[n][m] = Mat[n][m] + temp;
    }
    return table[n][m];
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>Mat[i][j];
    }
    cout<<minCost(n-1,m-1)<<endl;
    return 0;
}
