#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
#define ll long long
using namespace std;

string filename = "r.txt";

int p[maxn];

ll s[maxn];

pair < ll , pair < int , int > > e[maxn];

int n , pa , pb;

ll ans; 

const ll z = 1e9 + 7;

int fnd(int x)
{
    while(x != p[x])
    {
        x = p[x];
    }

    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if(fopen(filename.c_str() , "r")) freopen(filename.c_str() , "r" , stdin);

    cin >> n;

    for(int i = 1; i < n; i++)
    {
        s[i] = 1LL;

        cin >> e[i].second.first >> e[i].second.second >> e[i].first;

        p[i] = i;
    }

    s[n] = 1LL;

    p[n] = n;

    sort(e + 1 , e + n);

    for(int i = 1; i < n; i++)
    {
        pa = fnd(e[i].second.first);

        pb = fnd(e[i].second.second);

        ans = (ans + 1LL * e[i].first * s[pa] % z * s[pb] % z) % z;

        p[pa] = pb;

        s[pb] += s[pa];
    }

    cout << ans << endl;

    return 0;
}
