#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    long long int n,m,a;
    scanf("%lld %lld %lld",&n,&m,&a);
    long long int length=n/a;
    if(n%a!=0)
        length++;
    long long int breath=m/a;
    if(m%a!=0)
        breath++;
    printf("%lld\n",length*breath);
    return 0;
}
