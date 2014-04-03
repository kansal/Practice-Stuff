#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    long long int n,m,a;
    cin>>n>>m>>a;
    long long int length=n/a;
    if(n%a!=0)
        length++;
    long long int breath=m/a;
    if(m%a!=0)
        breath++;
    cout<<length*breath<<endl;
    return 0;
}
