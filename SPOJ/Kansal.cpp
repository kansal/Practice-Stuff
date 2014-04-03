#include<stdio.h>
#include<math.h>
#define si(n) scanf("%lld",&n)
long long int array[10]={0,1,3,6,10,15,21,28,36,45};
long long int dig(long long int a)
{
    int count=0;
    if(a==0)
        return 1;
    while(a!=0)
    {
        a/=10;
        count++;
    }
    return count;
}
long long int func(long long int a)
{
    long long int DIG=dig(a);
    if(DIG==1)
        return array[a];
    long long int val=a/pow(10,DIG-1);
    long long int val1=array[val-1]*pow(10,DIG-1);
    long long int val2=array[9]*(DIG-1)*(long long int)pow(10,DIG-2)*val;
    long long int val3=val*(a%(long long int)pow(10,DIG-1)+1);
    return val1+val2+val3+func(a%(long long int)pow(10,DIG-1));
}
int main()
{
    long long int tc;
    //si(tc);
    while(1)
    {
    long long int a,b;
    si(a);
    si(b);
    if(a==b && a==-1)
        break;
    printf("%lld\n",func(b)-func(a-1));
    }
    return 0;
}
