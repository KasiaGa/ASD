#include<iostream>
using namespace std;

void selectionSort(int *tab, int n)
{
    int minIndex;
    for(int i=0; i<n; i++)
    {
        minIndex=i;
        for(int j=i+1; j<n; j++)
        {
            if(tab[j]<tab[minIndex])
                minIndex=j;
        }
        if(minIndex!=i)
        swap(tab[i], tab[minIndex]);
    }

}

int main()
{
    int n;
    cout<<"enter the size on an array"<<endl;
    cin>>n;
    int *tab=new int[n];

    cout<<endl<<"enter the elements of an array"<<endl;
    for(int i=0; i<n; i++)
        cin>>tab[i];

    selectionSort(tab, n);

    cout<<endl<<"this is the result of using selection sort:"<<endl<<endl;
    for(int i=0; i<n; i++)
        cout<<tab[i]<<" ";

    cout<<endl;

    return 0;
}
