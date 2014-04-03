#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;

int dp[11];
int lis(vector <int> v,int n)
{
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j])
                dp[i]=max(1+dp[j],dp[i]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(dp[i],ans);
    return ans;
}

int main()
{
   vector <int> v;
   int n,k;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>k;
       v.push_back(k);
   }
   cout<<lis(v,n)<<endl;
}
