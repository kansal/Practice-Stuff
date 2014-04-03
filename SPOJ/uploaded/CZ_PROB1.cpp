#include<iostream>
#include<vector>
#include<string.h>

using namespace std;
vector <int> v;
int table[8000][1000];

bool isprime(int n)
{
    if(n&1 == 0)
        return false;
    for(int i=3;i<=n/2;i+=2)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

bool fermat(int n)
{
    if(n%4==1)
        return true;
    else return false;
}


void sp2()
{
    for(int n=2;n<8000;n++)
    {
        if(n==2)
            v.push_back(n);
        if(isprime(n) && fermat(n))
            v.push_back(n);
    }
}

int dp(int sum, int max)
{
    for(int i=0;i<=sum;i++)
    {
        for(int j=1;j<=max;j++)
        {
            if(i==0)
                table[i][j]=1;
            else
            {
                if(j==1)
                    table[i][j]=1;
                else
                {
                    if(i<j)
                        table[i][j]=table[i][j-1];
                    else
                        table[i][j]=table[i-j][j]+table[i][j-1];
                }
            }
        }
    }
        return table[sum][max];
}
int main()
{
    sp2();
    /*for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;*/
    int tc,n,k;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        cin>>n>>k;
        cout<<dp(v[n-1],k)<<endl;
    }
    return 0;
}
