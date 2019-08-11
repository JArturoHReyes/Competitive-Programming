#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string x;

int a[26];

map < int , int > lol;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextI.txt" , "r")) freopen("ArturoTextI.txt" , "r" , stdin);

    cin >> x;

    for(char c : x)
    {
        a[c - 'a']++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(a[i] > 0)
        {
            lol[a[i] & 1]++;
        }
    }

    /*for(auto it : lol)
    {
        cout << it.first << " " << it.second << endl;
    }*/

    if(lol.size() > 1)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << lol.begin()->first << endl;
    }

    return 0;
}
