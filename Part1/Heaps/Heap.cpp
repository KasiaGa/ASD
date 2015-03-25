/*  procedures: heapify, build heap, increase key, insert element,
    remove max, remove min */

#include<iostream>
#include<algorithm>
using namespace std;

int parent(int i)
{
    return (i-1)/2;
}

int left(int i)
{
    return 2*i+1;
}

int right(int i)
{
    return 2*i+2;
}

void heapify(int *A, int n, int i)
{
    int ind_max=i;
    int l=left(i);
    int r=right(i);
    if(l<n && A[l]>A[i])
        ind_max=l;
    if(r<n && A[r]>A[ind_max])
        ind_max=r;
    if(ind_max!=i)
    {
        swap(A[ind_max], A[i]);
        heapify(A, n, ind_max);
    }
}

void buildHeap(int *A, int n)
{
    for(int i=parent(n-1); i>=0; i--)
        heapify(A, n, i);
}

void increaseKey(int *A, int i, int key)
{
    A[i]=key;
    while(parent(i)!=i && A[parent(i)]<A[i])
    {
        swap(A[parent(i)], A[i]);
        i=parent(i);
    }
}

void insertElement(int *A, int value, int &n, int maxSize)
{
    if(n<maxSize)
    {
        n++;
        increaseKey(A, n-1, value);
    }
    else
        cout<<"heap overflow!!"<<endl;
}

void print(int *A, int n)
{
    for(int i=0; i<n; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int removeMax(int *A, int &n, int maxSize)
{
    if(n!=0)
    {
        int maxElement=A[0];
        A[0]=A[n-1];
        n--;
        heapify(A, n, 0);
        return maxElement;
    }
    else
        cout<<"heap underflow!!"<<endl;
        return -1;
}

int removeMin(int *A, int &n, int MaxSize)
{
    if(n!=0)
    {
        int minElement=A[n/2-1];
        int minIndex;
        for(int i=n/2; i<n; i++)
        {
            if(minElement>A[i])
            {
                minElement=A[i];
                minIndex=i;
            }
        }
        A[minIndex]=A[n-1];
        n--;
        heapify(A, n, minIndex);
        return minElement;
    }
    else
    {
        cout<<"heap underflow!!"<<endl;
        return -1;
    }
}

int main()
{
    int maxSize=1000;
    int *A=new int[maxSize];
    int n;
    cout<<"enter the size of the heap"<<endl;
    cin>>n;
    cout<<"enter the elements of the heap"<<endl;
    for(int i=0; i<n; i++)
        cin>>A[i];

    buildHeap(A, n);
    string command;
    int value, index;

    cout<<"commands: PRINT, INSERT value, SET index value, REMOVEMAX, REMOVEMIN"<<endl<<endl;
    while(true)
    {
        cin>>command;
        if(command=="PRINT")
            print(A, n);
        if(command=="INSERT")
        {
            cin>>value;
            insertElement(A, value, n, maxSize);
        }
        if(command=="SET")
        {
            cin>>index;
            cin>>value;
            if(A[index]<value)
                increaseKey(A, index, value);
            else
            {
                increaseKey(A, index, value);
                heapify(A, n, index);
            }
        }
        if(command=="REMOVEMAX")
        {
            cout<<removeMax(A, n, maxSize)<<endl;
        }
        if(command=="REMOVEMIN")
        {
            cout<<removeMin(A, n, maxSize)<<endl;
        }
    }

    return 0;
}
