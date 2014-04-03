/*Josephus problem*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;
/*long int table[66000000];

This is the DP for the code but its solvable without that as well.
int dp(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
            table[i]=2*table[i/2]-1;
        else
            table[i]=2*table[i/2]+1;
    }
    return table[n];
}*/
int func(int n)
{
    long int c=1;
    while(c<=n)
        c=c<<1;
    c=c>>1;
    return ((n-c)<<1) + 1;
}
int main()
{
 //   table[1]=1;
    while(1)
    {
        string str;
        cin>>str;
        long int n=((str[0]-'0')*10+(str[1]-'0'))*pow(10,str[3]-'0');
        if(n==0)
            break;
        cout<<func(n)<<endl;
    }
    return 0;
}

