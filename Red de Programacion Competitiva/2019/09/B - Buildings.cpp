#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll z = 1e9 + 7;

// burnside lemma

ll fpow(ll b , ll e)
{
    ll ret = 1;

    while(e)
    {
        if(e & 1)
        {
            ret = (ret * b) % z;
        }

        b = b * b % z;

        e >>= 1;
    }

    return ret;
}

ll n , m , c , ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextB.txt" , "r")) freopen("ArturoTextB.txt" , "r" , stdin);

    cin >> n >> m >> c;

    n = fpow(c , n * n);

    for(ll i = 0; i < m; i++)
    {
        ans = (ans + fpow(n , __gcd(m , i))) % z;
    }

    cout << ans * fpow(m , z - 2) % z << endl;

    return 0;
}
