/* finding the sum of the coherent subsequence in O(nlogn) time */

#include<iostream>
#include<algorithm>
using namespace std;

int maxElement(int a, int b, int c)
{
    int max1=max(a, b);
    return max(max1, c);
}

int ssp(int *A, int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return max(A[0], 0);

    int l, r;
    l=ssp(A, n/2);
    r=ssp(A+n/2, n-(n/2));

    int lPrim=0, lPartial=0;
    for(int i=n/2-1; i>=0; i--)
    {
        lPartial+=A[i];
        if(lPartial>lPrim)
            lPrim=lPartial;
    }

    int rPrim=0, rPartial=0;
    for(int i=n/2; i<n; i++)
    {
        rPartial+=A[i];
        if(rPartial>rPrim)
            rPrim=rPartial;
    }

    return maxElement(l, r, lPrim+rPrim);
}

int main()
{
    int n, result;
    cout<<"enter the length of an array"<<endl;
    cin>>n;
    int *A=new int[n];

    cout<<endl<<"enter the elements of an array"<<endl;
    for(int i=0; i<n; i++)
        cin>>A[i];

    result=ssp(A, n);

    cout<<endl<<"the sum of the coherent subsequence: "<<result<<endl;

    return 0;
}

