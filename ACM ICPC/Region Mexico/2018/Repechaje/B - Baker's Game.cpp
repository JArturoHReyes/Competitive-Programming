#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1000010
using namespace std;

const ll z = 1e9 + 7;

ll fact[maxn] , rfact[maxn];

ll fpow(ll b , ll e)
{
    ll ret = 1;

    while(e)
    {
        if(e & 1)
        {
            ret = ret * b % z;
        }

        b = b * b % z;

        e >>= 1;
    }

    return ret;
}

ll nk(ll n , ll k)
{
    if(n < k)
    {
        return 0ll;
    }

    return fact[n] * rfact[k] % z * rfact[n - k] % z;
}

ll n , k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*ll n , ans = 0 , p;

    cin >> n >> p;

    vector < int > lol;

    for(int i = 1; i <= n; i++)
    {
        lol.push_back(i);
    }

    do
    {
        bool ok = true;

        if(lol[p - 1] == p)
        {
            for(int i = 0; i < p - 1; i++)
            {
                if(lol[i] == i + 1)
                {
                    ok = false;

                    break;
                }
            }

            if(ok)
            {
                ans++;
            }
        }
    }
    while(next_permutation(lol.begin() , lol.end()));

    cout << "real ans = " << ans << endl;

    fact[0] = 1ll;
fact[0] = 1ll;

    for(ll i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % z;
    }
    for(ll i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % z;
    }

    ll goodans = fact[n - 1] , quitar;

    if(n > 1)
    {
        quitar = fact[n - 2];
    }

    //cout << "before = " << goodans << endl;

    // cout << "quitar = " << quitar << endl;

    for(ll i = 2; i <= p; i++)
    {
        goodans -= quitar;

        //cout << "after = " << goodans << endl;

        if(n - i - 1 >= 0)
        {
            quitar -= fact[n - i - 1];
        }

        //cout << "quitar = " << quitar << endl;
    }

    cout << goodans << endl;*/

    fact[0] = 1ll;

    for(ll i = 1; i < maxn; i++)
    {
        fact[i] = (fact[i - 1] * i) % z;
    }

    rfact[maxn - 1] = fpow(fact[maxn - 1] , z - 2);

    for(ll i = maxn - 2; i >= 0; i--)
    {
        rfact[i] = rfact[i + 1] * (i + 1) % z;
    }

    cin >> n >> k;

    n-- , k--;

    ll ans = 0ll;

    for(ll i = 0; i <= k; i++)
    {
        int positive = (i & 1) ? -1 : 1;

        ans = (ans + fact[n - i] * nk(k , i) * positive % z + z) % z;
    }

    cout << ans << endl;

    return 0;
}
