#include<iostream>

using namespace std;

int n,table[2001][2001],v[2001];
int func()
{
    int j,age;
    for(int l=1;l<n;l++)
    {
        for(int i=0;i<n-l+1;i++)
        {
            j=i+l;
            age=n-(j-i);
            table[i][j]=max(table[i+1][j]+v[i]*age,table[i][j-1]+v[j]*age);
        }
    }
    return table[0][n-1];
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        table[i][i]=v[i]*n; //age=n for this case
    }
    cout<<func()<<endl;
    return 0;
}
