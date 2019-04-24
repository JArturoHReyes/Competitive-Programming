#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1000010
using namespace std;

bool prime[maxn];

ll x;

void sieve()
{
    prime[0] = prime[1] = 1;

    for(int i = 2; i <= maxn; i++)
    {
        if(!prime[i])
        {
            for(int j = i + i; j <= maxn; j += i)
            {
                prime[j] = 1;
            }
        }
    }
}

ll resta(ll x)
{
    for(ll i = 2; i <= x; i++)
    {
        if(!prime[i] && !prime[x - i])
        {
            return (x - i) - i;
        }
    }

    return -1;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();

    cin >> x;

    int ans = 0;

    while(x > 3)
    {
        x = resta(x);

        ans++;
    }

    cout << ans << endl;

    return 0;
}
