#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>

using namespace std;

int table[1000];
int fibo(int n)
{
    if( n==1)
        return 1;
    else if(n==0)
        return 0;
    if(table[n]!=-1)
        return table[n];
    else
    {
        table[n]=fibo(n-1)+fibo(n-2);
        return table[n];
    }
}
int main()
{
    int n;
    memset(table,-1,sizeof(table));
    cin>>n;
    cout<<fibo(n);
}
