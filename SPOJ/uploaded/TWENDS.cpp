#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> a;
int table[1000][1000];
int dp(int i, int j)
{
    if(table[i][j]!=-1)
        return table[i][j];
    int sum1=0,sum2=0;
    if(i==j)
        return a[i];
    else if(i>j) return 0;
    //ith taken
    if(a[i+1]>=a[j]) sum1+=a[i]+dp(i+2,j);
    else sum1+=a[i]+dp(i+1,j-1);
    //jth taken
    if(a[j-1]>a[i]) sum2+=a[j]+dp(i,j-2);
    else sum2+=a[j]+dp(i+1,j-1);
    table[i][j]=max(sum1,sum2);
    return table[i][j];
}

int main()
{
    int n,k,sum,tc=1;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        memset(table,-1,sizeof(table));
        sum=0;
        a.clear();
        for(int i=0;i<n;i++)
        {
            cin>>k;
            a.push_back(k);
            sum+=k;
        }
        int num1=dp(0,a.size()-1);
        int num2=sum-num1;
        cout<<"In game "<<tc<<", the greedy strategy might lose by as many as "<<num1-num2<<" points."<<endl;
        tc++;
    }
    return 0;
}

