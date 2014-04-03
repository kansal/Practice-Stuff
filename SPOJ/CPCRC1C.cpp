#include<iostream>
#include<vector>

using namespace std;

int arr[]={0,1,3,6,10,15,21,28,36,45};

int func(int n)
{
    int a=n%10;
    while(b/10)
    {
        sum+=b%10;
        b/=10;
        p++;
    }
    for(int i=1;i<=b;i++)
        sum1+=i*pow(10,p);
    return sum*(a+1) + arr[a] + sum1 + func(newn);
}

int main()
{
    int n,m;
    while(1)
    {
        cin<<n<<m;
        if(n==-1 && m==-1)
            break;
        cout<<func(m)-func(n-1)<<endl;
    }
    return 0;
}
