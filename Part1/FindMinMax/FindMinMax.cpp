/* finding maximum and minimum in (3/2)*n time */

#include<iostream>
#include<limits>
using namespace std;

void minMax(int *tab, int *result, int n)
{
    for(int i=0; i<n-1; i+=2)
    {
        if(tab[i]>tab[i+1]) // checking if the first element is greater than the second
        {
            if(result[0]<tab[i]) // checking if the first element is the new maximum
                result[0]=tab[i];
            if(result[1]>tab[i+1]) // checking if the second element is the new minimum
                result[1]=tab[i+1];
        }
        else // if the second element is greater
        {
            if(result[0]<tab[i+1]) // checking if the second element is the new max
                result[0]=tab[i+1];
            if(result[1]>tab[i]) // checking if the first element is the new min
                result[1]=tab[i];
        }
    }
}

int main()
{
    int n;
    cout<<"enter the size of an array"<<endl;
    cin>>n;
    int *tab=new int[n];

    cout<<endl<<"enter the elements"<<endl;
    for(int i=0; i<n; i++)
        cin>>tab[i];

    int result[2];
    result[0]=INT_MIN;
    result[1]=INT_MAX;

    minMax(tab, result, n);

    cout<<endl<<"max: "<<result[0]<<endl<<"min: "<<result[1]<<endl;

    return 0;
}
