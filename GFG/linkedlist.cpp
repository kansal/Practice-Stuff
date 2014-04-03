/* Linked List: Dyanmic Memory allocation, non continuous, ease of insertion and deletiokn*/
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct node{
    int data;
    node* next;
}node;
void printlist(node* root)
{
    if(root==NULL)
        printf("\n");
    else
    {
        while(root!=NULL)
        {
            printf("%d ",root->data);
            root=root->next;
        }
        printf("\n");
    }
}
node* pushStart(node* root, int n)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=n;
    newnode->next=root;
    return newnode;
}
node* pushLast(node* root, int n)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=n;
    newnode->next=NULL;
    node* temp=root;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
    return root;
}
node* pushMid(node* root, int n, int find)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data=n;
    node* temp=root;
    while(temp->data!=find)
        temp=temp->next;
    node* temp1;
    temp1=temp->next;
    temp->next=newnode;
    newnode->next=temp1;
    return root;
}
/*node* deleteHead(node* root)
{
    root=root->next;
    return root;
}*/
void deleteHead(node** root)
{
    *root=(*root)->next;
}
void Nthfromend(node* root,int n)
{
    node* temp1=root;
    node* temp2=root;
    int i=0;
    while(1)
    {
        if(i==n)
            break;
        temp1=temp1->next;
        i++;
    }
    while(temp1!=NULL)
    {
        temp1=temp1->next;
        temp2=temp2->next;
    }
    cout<<temp2->data<<endl;
}
void middle(node* root)
{
    node* temp1=root;
    node* temp2=root;
    while(temp1!=NULL && temp1->next!=NULL)
    {
        temp1=temp1->next->next;
        temp2=temp2->next;
    }
    cout<<temp2->data<<endl;
}
void deleteonlynode(node* a)
{
    a->data=a->next->data;
    a->next=a->next->next;
}

//-----------------------------//
node* deletelist(node* root)
{
    node* current = root;
    node* next;
    while(current!=NULL)
    {
        next=current->next;
        free(current);
        current=next;
    }
    root=NULL;
    return root;
}

//----------------------------//
node* reverse(node* root)
{
    node* next;
    node* prev=NULL;
    node* current=root;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}

int loop(node* root)
{
    node *fast, *slow;
    while(fast && slow && fast->next)
    {
        if(slow == fast)
            return 1;
    }
    return 0;
}
int main()
{
    node *head=NULL;
    node *second=NULL;
    node *third=NULL;
    head=(node*)malloc(sizeof(node));
    second=(node*)malloc(sizeof(node));
    third=(node*)malloc(sizeof(node));
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    head=pushLast(head,10);
    head=pushLast(head,16);
    head=pushStart(head,0);
    head=pushMid(head,11,2);
    //deleteHead(&head);
    //deleteHead(&head);
    printlist(head);
    Nthfromend(head,4);
    deleteonlynode(third);
    printlist(head);
    //head=deletelist(head);
    head=reverse(head);
    printlist(head);
}

/*int main()
{
    node arr[10];
    for(int i=0;i<10;i++)
    {
        arr[i].data=i;
        if(i!=9)
        arr[i].next=arr+i+1;
        else
        arr[i].next=NULL;
    }
    node* temp=arr;
    int i=0;
    while(temp!=NULL)
    {
        printf("%d\n",(arr+i)->data);
        temp=temp->next;
        i++;
    }
    return 0;
}*/

