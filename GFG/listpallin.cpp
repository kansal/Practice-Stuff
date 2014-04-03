#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct node{
    int data;
    node* next;
}node;

node* middle(node * root)
{
    node *fast=root;
    node *slow=root;
    while(fast->next!=NULL && fast!=NULL )
    {
        fast=fast->next->next;
        cout<<fast->data<<endl;
        slow=slow->next;
    }
    cout<<slow->data<<endl;
    return slow;
}

node* reverse(node* root)
{
    node* current=root;
    node* next;
    node* prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}

node* insert(node* root,int n)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->next=NULL;
    newnode->data=n;
    if(root==NULL)
        root=newnode;
    else
    {
        node* temp=root;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
    return root;

}
void printlist(node* root)
{
    while(root!=NULL)
    {
        cout<<root->data<<' ';
        root=root->next;
    }
    cout<<endl;
}
int main()
{
    node* root=NULL;
    for(int i=0;i<11;i++)
        root=insert(root,i);
    node* temp=middle(root);
    temp=temp->next; // assuming odd sized list
    printlist(root);
    printlist(temp);
    //root=reverse(root);
    //printlist(root);
    temp=reverse(temp);
    printlist(temp);
    return 0;
}
