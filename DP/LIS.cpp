#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
vector <int> v;
vector <int> table(1000,0);
int lis(int n)
{
    if(n==0)
        return 1;
    int temp;
    if(table[n]==0)
    {
        for(int j=n;j>0;j--)
        {
            for(int i=j-1;i>=0;i--)
            {
                if(v[i]<v[j]) temp=1+lis(i);
                else temp=lis(i);
                if(temp>table[n]) table[n]=temp;
            }
        }
    }
    return table[n];
}
int main()
{
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    lis(n-1);
    cout<<*max_element(table.begin(),table.end())<<endl;
}
