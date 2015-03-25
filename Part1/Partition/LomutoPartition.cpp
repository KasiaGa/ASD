/* Lomuto Partition */

#include<iostream>
#include<algorithm>
using namespace std;

int Partition(int *A, int p, int r)
{
    int x=A[r];
    int i=p-1;
    for(int j=p; j<r; j++)
    {
        if(A[j]<=x)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    i++;
    swap(A[i], A[r]);
    return i;
}

int main()
{
    int n;
    cout<<"enter the size of an array"<<endl;
    cin>>n;
    int *A=new int[n];

    cout<<endl<<"enter the elements of an array"<<endl;
    for(int i=0; i<n; i++)
        cin>>A[i];

    int x=Partition(A, 0, n-1); // index of an element such that all elements on the left are
                                // lower or equal, on the right - greater
    cout<<endl<<"index: "<<x<<" value: "<<A[x]<<endl;

    cout<<endl<<"array after partition:"<<endl;
    for(int i=0; i<n; i++)
        cout<<A[i]<<" ";

    cout<<endl;

    return 0;
}
