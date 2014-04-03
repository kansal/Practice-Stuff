#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[100],table[100];
int maxseq(int n)
{
    for(int i=1;i<n;i++)
    {
        int maxcount=table[i-1];
        for(int j=0;j<i;j++)
        {
            if(arr[i]<arr[j])
            maxcount=max(maxcount,table[j]+arr[i]);
        }
            table[i]=maxcount;
    }
    return table[n-1];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    table[0]=arr[0];
    cout<<maxseq(n);
    return 0;
}
