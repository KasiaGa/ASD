/* creating a tree and printing it in pre-order, in-order and post-order traversal */

#include<iostream>
using namespace std;

struct node
{
    node *left;
    node *right;
    node *parent;
    int value;
};

void add(node *&proot, int v)
{
    if(proot==NULL)
    {
        proot=new node;
        proot->parent=proot->right=proot->left=NULL;
        proot->value=v;
        return;
    }

    if(v<proot->value && proot->left==NULL)
    {
        proot->left=new node;
        proot->left->value=v;
        proot->left->parent=proot;
        proot->left->left=proot->left->right=NULL;
        return;
    }

    if(v>proot->value && proot->right==NULL)
    {
        proot->right=new node;
        proot->right->value=v;
        proot->right->parent=proot;
        proot->right->left=proot->right->right=NULL;
        return;
    }

    if(v<proot->value)
        add(proot->left, v);
    else
        add(proot->right, v);
}

void printTreePreorder(node *proot) // pre-order traversal
{
    if(proot!=NULL)
    {
        cout<<proot->value<<" ";
        printTreePreorder(proot->left);
        printTreePreorder(proot->right);
    }
}

void printTreeInorder(node *proot) // in-order traversal
{
    if(proot!=NULL)
    {
        printTreeInorder(proot->left);
        cout<<proot->value<<" ";
        printTreeInorder(proot->right);
    }
}

void printTreePostorder(node *proot) // post-order traversal
{
    if(proot!=NULL)
    {
        printTreePostorder(proot->left);
        printTreePostorder(proot->right);
        cout<<proot->value<<" ";
    }
}

int main()
{
    node *proot=NULL;
    int n, v;

    cout<<"enter the number of nodes"<<endl;
    cin>>n;

    cout<<"enter the values"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>v;
        add(proot, v);
    }

    cout<<endl<<"pre-order traversal:"<<endl;
    printTreePreorder(proot);
    cout<<endl<<endl<<"in-order traversal:"<<endl;
    printTreeInorder(proot);
    cout<<endl<<endl<<"post-order traversal:"<<endl;
    printTreePostorder(proot);
    cout<<endl;

    return 0;
}
