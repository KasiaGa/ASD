/* finding kth biggest element in an unsorted array */

#include<iostream>
#include<algorithm>
using namespace std;

int Partition(int *A, int n)
{
    int x=A[n];
    int i=-1;
    for(int j=0; j<n; j++)
    {
        if(A[j]<=x)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    i++;
    swap(A[i], A[n]);
    return i;
}

int select(int *A, int n, int k)
{
    if(n<=1)
        return A[0];
    int q=Partition(A, n-1);
    if(k==q)
        return A[k];
    else if(k<q)
        return select(A, q, k);
    else
        return select(A+q+1, n-(q+1), k-(q+1));
}

int main()
{
    int n, k, x;
    cout<<"enter the number of elements"<<endl;
    cin>>n;

    cout<<"enter the elements"<<endl;
    int *A=new int[n];
    for(int i=0; i<n; i++)
        cin>>A[i];

    cout<<"enter k"<<endl;
    cin>>k;
    x=select(A, n, k-1);

    cout<<endl<<k<<" biggest element:"<<endl;
    cout<<x<<endl;

    return 0;
}
