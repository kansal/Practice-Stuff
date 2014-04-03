#include<iostream>
#include<algorithm>
#include<vector>

int val[100],table[100];
using namespace std;
int rod(int n)
{
    for(int i=0;i<=n;i++)
    {
        int maxcount=0;
        for(int j=0;j<i;j++)
            maxcount=max(maxcount,val[j]+table[i-j-1]);
        table[i]=maxcount;
    }
    return table[n];
}

int main()
{
    int n,length;
    cin>>length;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>val[i];
    table[0]=0;
    table[1]=val[0];
    cout<<val[1]<<endl;
    cout<<rod(length);
    return 0;
}
