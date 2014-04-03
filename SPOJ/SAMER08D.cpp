#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int table[100][100];
string a,b;
int lcs(int n, int m, int k)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j])
                table[i][j]=1+table[i-1][j-1];
            else
            {
                if(i!=0 && j!=0)
                    table[i][j]=max(table[i-1][j],table[i][j-1]);
                else
                {
                    if(i==0 && j!=0)
                    table[i][j]=table[i][j-1];
                    else if(j==0 && i!=0)
                        table[i][j]=table[i-1][j];
                    else table[i][j]=0;
                }
            }
            if(table[i][j]>=k)
            {
                cout<<i<<' ' <<j<<' '<<table[i][j]<<endl;
                return table[i][j];
            }
        }
    }
    return table[n-1][m-1];
}
int main()
{
    int k;
    cin>>k;
    cin>>a>>b;
    int temp=lcs(a.size(),b.size(),k);
    if(temp >= k)
        cout<<temp<<endl;
    else
        cout<<"0"<<endl;
    return 0;
}
