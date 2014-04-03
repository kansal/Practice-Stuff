#include<iostream>
#include<string.h>

using namespace std;

long long int table[65][10];

long long int dp(int n,int prev)
{
    for(int k=prev+1;k<=n;k++)
    {
        for(int i=0;i<10;i++)
        {
            if(k==1)
                table[k][i]=1;
            else
            {
                for(int j=i;j<10;j++)
                    table[k][i]+=table[k-1][j];
            }
        }
    }
    long long int ans=0;
    for(int i=0;i<10;i++)
        ans+=table[n][i];
    return ans;
}
int main()
{
    int tc,prev=0;
    cin>>tc;
    memset(table,0,sizeof(table));
    for(int i=1;i<=tc;i++)
    {
        int n,trash;
        cin>>trash>>n;
        if(n<prev)
        {
            int ans=0;
            for(int i=0;i<10;i++)
                ans+=table[n][i];
            cout<<trash<<" "<<ans<<endl;
        }
        else
            cout<<i<<" "<<dp(n,prev)<<endl;
        prev=n;
    }
    return 0;
}
