/*  checking if 2 words are anagrams, considering that the alphabet consists
    of 26 letters */

#include<iostream>
using namespace std;

bool anagram(string a, string b)
{
    int t[26];
    for(int i=0; i<26; i++)
        t[i]=0;

    for(int i=0; i<a.length(); i++)
        t[a[i]-'a']++;
    for(int i=0; i<b.length(); i++)
        t[b[i]-'a']--;

    for(int i=0; i<26; i++)
        if(t[i]!=0)
        return false;
    return true;
}

int main()
{
    string a, b;
    cout<<"enter the first word"<<endl;
    cin>>a;

    cout<<"enter the second word"<<endl;
    cin>>b;

    cout<<endl;

    if(anagram(a, b))
        cout<<"yes, these are anagrams"<<endl;
    else
        cout<<"no, these are not anagrams"<<endl;

    return 0;
}
