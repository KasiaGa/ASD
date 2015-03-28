/*  QuickerSort: dividing the list into 3 parts: lower than x, equal and greater
    then recursively sorting all the lower and greater */

#include<iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};

struct dividingPoint
{
    node *beginning;
    node *finish;
};

node *getTail(node *head)
{
    while(head->next!=NULL)
        head=head->next;

    return head;
}

dividingPoint divideList(node *first, node *last, int x)
{
    dividingPoint d;

    node *lower=NULL;
    node *higher=NULL;
    node *equals=NULL;

    node *p=first;
    node *temp;

    p=p->next;
    while(p!=last)
    {
        temp=p->next;

        if(p->value<x)
        {
            p->next=lower;
            lower=p;
        }
        else
        if(p->value==x)
        {
            p->next=equals;
            equals=p;
        }
        else
        if(p->value>x)
        {
            p->next=higher;
            higher=p;
        }

        p=temp;
    }

    if(lower!=NULL)
    {
        first->next=lower;

        while(first->next!=NULL)
        {
            first=first->next;
        }
    }

    if(equals!=NULL)
    {
        first->next=equals;

        /* saving first equal */
        d.beginning=first->next;

        while(first->next!=NULL)
        {
            first=first->next;
        }
    }

    /* saving last equal */
    d.finish=first;

    if(higher!=NULL)
    {
        first->next=higher;

        while(first->next!=NULL)
        {
            first=first->next;
        }
    }
    first->next=last;
    return d;

}


void quickersort(node *start, node *end1)
{
    if(start->next!=end1)
    {
        dividingPoint d1=divideList(start, end1, start->next->value);
        quickersort(start, d1.beginning);
        quickersort(d1.finish, end1);
    }

}


int main()
{
    node *head=new node;
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

    cout<<endl<<"the list before sorting:"<<endl;

    while(p->next->next!=NULL)
    {
        cout<<p->next->value<<" ";
        p=p->next;
    }

    node *tail;
    tail=getTail(head);

    cout<<endl<<endl<<"the list after using QuickerSort:"<<endl;

    quickersort(head, tail);

    p=head;
    while(p->next->next!=NULL)
    {
        cout<<p->next->value<<" ";
        p=p->next;
    }

    cout<<endl;

    return 0;
}

