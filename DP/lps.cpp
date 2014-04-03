#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

int lps(char *str,int n, int m)
{
    if(n==m)
        return 1;
    if(n>m)
        return 0;
    if(str[n] == str[m])
        return 2+lps(str,n+1,m-1);
    else return max(lps(str,n+1,m),lps(str,n,m-1));
}
int main()
{
    char str[]="geeksforgeeks";
    int n=strlen(str);
    cout<<lps(str,0,n-1);
    return 0;
}
