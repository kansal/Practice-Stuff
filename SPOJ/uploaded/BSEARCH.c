#include<stdio.h>

int bsearch(int arr[], int query,int first, int last);
int main()
{
    int N,Q,arr[100001],query;
    scanf("%d %d",&N,&Q);
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<Q;i++)
    {
        scanf("%d",&query);
        printf("%d\n",bsearch(arr,query,0,N-1));
    }

    return 0;
}

int bsearch(int arr[], int query,int first, int last)
{
    int mid=(first+last)/2;
    while(first<=last)
    {
    mid=(first+last)/2;
        if(query==arr[mid])
        {
            int temp=bsearch(arr,query,0,mid-1);
            if(temp==-1)
                return mid;
            else return temp;
        }
        else
        {
            if(arr[mid]>query)
                last=mid-1;
            else first=mid+1;
        }
    }
    return -1;
}
