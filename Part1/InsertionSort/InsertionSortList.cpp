#include<iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};

void insertElement(node *head, node *element)
{
    node *p, *prev;
    prev=head;
    p=prev->next;

    while(p!=NULL && (p->value<element->value))
    {
        p=p->next;
        prev=prev->next;
    }

    prev->next=element;
    element->next=p;
}

node *insertionsort(node *head)
{
    node *newHead=new node;
    newHead->next=NULL;
    node *temp;

    while(head->next!=NULL)
    {
        temp=head->next;
        head->next=head->next->next;
        insertElement(newHead, temp);
    }

    delete head;
    return newHead;
}

int main()
{
    node *head=new node; // creating the list with guards
    head->next=NULL;
    node *p;
    int n, number;
    cout<<"enter the length of the list"<<endl;
    cin>>n;

    cout<<endl<<"enter the elements of the list"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>number;
        p=new node;
        p->value=number;
        p->next=head;
        head=p;
    }

    p=new node;
    p->next=head;
    head=p;

    p=insertionsort(head);

    cout<<endl<<"this is the result of using insertion sort:"<<endl;

    while(p->next->next!=NULL)
    {
        cout<<p->next->value<<" ";
        p=p->next;
    }

    cout<<endl;

    return 0;
}
