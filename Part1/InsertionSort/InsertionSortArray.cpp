#include<iostream>
using namespace std;

void insertionSort(int *tab, int n)
{
    int j;
    for(int i=1; i<n; i++)
    {
            j=i;
        while(j>0 && tab[j-1]>tab[j])
        {
            swap(tab[j-1], tab[j]);
            j--;
        }
    }
}

int main()
{
    int n;
    cout<<"enter the size of an array"<<endl;
    cin>>n;
    int *tab=new int[n];

    cout<<endl<<"enter the elements of an array"<<endl;
    for(int i=0; i<n; i++)
        cin>>tab[i];

    insertionSort(tab, n);

    cout<<endl<<"this is the result of using insertion sort:"<<endl<<endl;
    for(int i=0; i<n; i++)
        cout<<tab[i]<<" ";

    cout<<endl;

    return 0;
}
