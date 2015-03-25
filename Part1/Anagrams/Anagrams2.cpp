/*  checking if 2 words are anagrams, considering that the alphabet consists
    of n letters where n is a big number */

#include<iostream>
using namespace std;

bool anagram(string a, string b, int n)
{
    int *t=new int[n];
    for(int i=0; i<a.length(); i++)
        t[a[i]]=0;
    for(int i=0; i<b.length(); i++)
        t[b[i]]=0;

    for(int i=0; i<a.length(); i++)
        t[a[i]]++;
    for(int i=0; i<b.length(); i++)
        t[b[i]]--;

    for(int i=0; i<a.length(); i++)
        if(t[a[i]]!=0)
            return false;
    for(int i=0; i<b.length(); i++)
        if(t[b[i]]!=0)
            return false;

    return true;
}

int main()
{
    string a, b;
    int n;
    cout<<"enter the first word"<<endl;
    cin>>a;

    cout<<"enter the second word"<<endl;
    cin>>b;

    cout<<"enter the length of the alphabet"<<endl;
    cin>>n;

    cout<<endl;

    if(anagram(a, b, n))
        cout<<"yes, these are anagrams"<<endl;
    else
        cout<<"no, these are not anagrams"<<endl;

    return 0;
}
