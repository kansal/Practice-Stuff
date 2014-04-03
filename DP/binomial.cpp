#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
int table[100][100];
int bionomial(int n,int k)
{
    if(k==0 || n==k)
        return 1;
    if(table[n][k]!=-1)
        return table[n][k];
    else
    {
        table[n][k]=bionomial(n-1,k-1)+bionomial(n-1,k);
        return table[n][k];
    }
}
int main()
{
    int n,k;
    memset(table,-1,sizeof(table));
    cin>>n>>k;
    cout<<bionomial(n,k)<<endl;
    return 0;
}
