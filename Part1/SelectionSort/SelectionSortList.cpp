#include<iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};

node *selectElement(node *head)
{
    node *minimum;
    minimum=head->next;
    node *prev=head;

    while(head->next!=NULL)
    {
        if(head->next->value<minimum->value)
        {
            minimum=head->next;
            prev=head;
        }
            head=head->next;
    }

    if(minimum!=NULL)
    {
        prev->next=minimum->next;
        minimum->next=NULL;
    }

    return minimum;
}

node *selectionsort(node *head)
{
    node *newHead=new node;
    newHead->next=NULL;
    node *minimum=selectElement(head);

    while(minimum)
    {
        minimum->next=newHead;
        newHead=minimum;
        minimum=selectElement(head);
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

    p=selectionsort(head);

    cout<<endl<<"this is the result of using selection sort:"<<endl;

    while(p->next->next!=NULL)
    {
        cout<<p->next->value<<" ";
        p=p->next;
    }

    cout<<endl;

    return 0;
}

