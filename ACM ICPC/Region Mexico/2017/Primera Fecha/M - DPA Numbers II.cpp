#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1000010
#define ll long long
using namespace std;

bool prime[maxn];

vector < ll > primes;

void sieve()
{
    for(ll i = 2; i < maxn; i++)
    {
        if(!prime[i])
        {
            for(ll j = i * i; j < maxn; j += i)
            {
                prime[j] = true;
            }

            primes.push_back(i);
        }
    }
}

ll expbin(ll b , ll e)
{
    if(e == 0)
    {
        return 1;
    }

    if(e == 1)
    {
        return b;
    }

    ll nextpow = expbin(b , e / 2);

    nextpow *= nextpow;

    if(!(e & 1))
    {
        return nextpow;
    }

    return (nextpow * b);
}

ll sumdiv(ll n)
{
    ll pf_idx = 0 , pf = primes[0] , ans = 1;

    while(pf * pf <= n)
    {
        ll power = 0;

        while(n % pf == 0)
        {
            n /= pf;

            power++;
        }

        ans *= (expbin(pf , power + 1) - 1) / (pf - 1);

        pf = primes[++pf_idx];
    }

    if(n != 1)
    {
        ans *= (expbin(n , 2) - 1) / (n - 1);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();

    int t;

    ll n;

    cin >> t;

    while(t--)
    {
        cin >> n;

        ll ans = sumdiv(n) - n;

        if(ans < n)
        {
            cout << "deficient";
        }
        
        if(ans == n)
        {
            cout << "perfect";
        }
        
        if(ans > n)
        {
            cout << "abundant";
        }

        cout << endl;
    }

    return 0;
}
