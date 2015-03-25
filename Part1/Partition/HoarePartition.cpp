/* Hoare Partition */

#include<iostream>
#include<algorithm>
using namespace std;

int Partition(int *A, int n)
{
    int x=A[n-1];
    int left=0, right=n-2;
    while(left<=right)
    {
        while(A[left]<=x)
            left++;

        while(A[right]>x)
            right--;

        if(left<=right)
        {
            swap(A[left], A[right]);
            left++;
            right--;
        }
    }

    cout<<"right: "<<right<<" left: "<<left<<endl;


    swap(A[left], A[n-1]);

    return left;
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

    int x=Partition(A, n); // index of an element such that all elements on the left are
                                // lower or equal, on the right - greater
    cout<<endl<<"index: "<<x<<" value: "<<A[x]<<endl;

    cout<<endl<<"array after partition:"<<endl;
    for(int i=0; i<n; i++)
        cout<<A[i]<<" ";

    cout<<endl;

    return 0;
}
