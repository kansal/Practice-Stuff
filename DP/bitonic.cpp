#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int arr[100],table[100],table1[100];
int lis(int n)
{
    for(int i=1;i<n;i++)
    {
        int maxcount=table[i-1];
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            maxcount=max(maxcount,table[j]+1);
        }
        table[i]=maxcount;
    }
    return table[n-1];
}
int lds(int n)
{
    for(int i=n-2;i>=0;i--)
    {
        int maxcount=table1[i+1];
        for(int j=n-1;j>i;j--)
        {
            if(arr[i]>arr[j])
                maxcount=max(maxcount,table1[j]+1);
        }
        table1[i]=maxcount;
    }
    return table1[n-1];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    table[0]=1;
    table1[n-1]=1;
    lis(n);
    lds(n);
    for(int i=0;i<n;i++)
        cout<<table[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<table1[i]<<" ";
    cout<<endl;
    /*int maxcount=0,sum;
    for(int i=0;i<n;i++)
    {
        sum=table[i]+table1[i];
        if(sum>maxcount)
            maxcount=sum;
    }
    cout<<maxcount;*/
    return 0;
}
