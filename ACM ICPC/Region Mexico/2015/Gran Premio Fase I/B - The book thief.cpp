#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;

const ll z = 1e9;

map < ll , ll > f;

void pre()
{
    ll k = 2 , v = 2;

    while(v <= z)
    {
        f[v] = k++;

        v += k;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pre();

    while(cin >> n && n)
    {
        auto it = f.lower_bound(n);

        cout << it->first - n + 1 << " " << it->second << endl;
    }

    return 0;
}
