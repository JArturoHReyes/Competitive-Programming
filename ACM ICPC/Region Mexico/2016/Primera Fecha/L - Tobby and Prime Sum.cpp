#include<bits/stdc++.h>
#define endl '\n'
#define maxsum 5010
#define maxd 510
#define ll long long
using namespace std;

bool prime[maxsum];

ll dp[maxd][maxsum];

string l , r;

const ll z = 1e9 + 7;

void sieve()
{
    memset(prime , true , sizeof(prime));

    prime[0] = prime[1] = false;

    for(int i = 2; i < maxsum; i++)
    {
        if(prime[i])
        {
            for(int j = i * i; j < maxsum; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

bool isprime()
{
    int sum = 0;

    for(int i = 0; i < r.length(); i++)
    {
        sum += (r[i] - '0');
    }

    return prime[sum];
}

ll rec(ll len , ll actualsum)
{
    if(!len)
    {
        return prime[actualsum];
    }

    ll &c = dp[len][actualsum];

    if(~c)
    {
        return c;
    }

    c = 0;

    for(int i = 0; i < 10; i++)
    {
        c = (c + rec(len - 1 , actualsum + i)) % z;
    }

    return c;
}

ll solve(string x)
{
    ll ans = 0 , sum = 0;

    for(int i = 0; i < x.length(); i++)
    {
        for(int j = '0'; j < x[i]; j++)
        {
            ans = (ans + rec(x.length() - i - 1 , sum + (j - '0'))) % z;
        }

        sum += (x[i] - '0');
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();

    memset(dp , -1 , sizeof(dp));

    while(cin >> l >> r)
    {
        ll ans1 = solve(l);

        ll ans2 = solve(r);

        cout << (ans2 - ans1 + z + isprime()) % z << endl;
    }

    return 0;
}
