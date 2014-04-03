#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int v[1000];
int table[100][100];
int mult(int n, int m)
{
    if(m==n)
        return 0;
    else
    {
        if(table[n][m]!=-1)
            return table[n][m];

        else
        {
            int temp;
            for(int i=n;i<m;i++)
            {
                temp=mult(n,i)+mult(i+1,m)+(v[n-1]*v[i]*v[m]);
                if(temp<table[n][m] && table[n][m]!=-1)
                    table[n][m]=temp;
                else if(table[n][m]==-1)
                    table[n][m]=temp;
            }
            return table[n][m];
        }
    }
}
int main()
{
    memset(table,-1,sizeof(table));
    int k,val;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>val;
        v[i]=val;
    }
    cout<<mult(1,k-1)<<endl;
    return 0;
}
