#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

string filename = "s.txt";

const int z = 1e9 + 10;

set < pair < pair < int , int > , int > > t;

int n , f , s , e , d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if(fopen(filename.c_str() , "r")) freopen(filename.c_str() , "r" , stdin);

    cin >> n;

    t.insert(make_pair(make_pair(-z , z) , 1));

    for(int i = 0; i < n; i++)
    {
        cin >> f;

        auto l = t.lower_bound(make_pair(make_pair(f + 1 , f + 1) , 0));

        l--;

        s = l->first.first;

        e = l->first.second;

        d = l->second;

        t.insert(make_pair(make_pair(s , f) , d + 1));

        if(f < e)
        {
            t.insert(make_pair(make_pair(f + 1 , e) , d + 1));
        }

        t.erase(l);

        cout << d << " ";
    }

    cout << endl;

    return 0;
}
