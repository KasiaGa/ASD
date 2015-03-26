/* finding the sum of the coherent subsequence in O(n) time */

#include<iostream>
#include<algorithm>
using namespace std;

int ssp(int *A, int n)
{
    int result=0;
    int partial=0;

    for(int i=0; i<n; i++)
    {
        partial+=A[i];
        partial=max(0, partial);
        if(partial>result)
            result=partial;
    }

    return result;
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
