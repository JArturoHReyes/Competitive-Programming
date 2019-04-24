#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1003
using namespace std;

int t;

const ll z = 1000000007;

ll memo[maxn][maxn];

ll dp(int l , int k)
{
    if(l == 0 && k == 0)
    {
        return 1;
    }

    if(l < 0 || k < 0)
    {
        return 0;
    }

    if(memo[l][k] != -1)
    {
        return memo[l][k];
    }

    ll ans = 0;

    if(l & 1)
    {
        ans = 10 * dp(l - 1 , k - 1);
    }
    else
    {
        ans = 10 * 9 * dp(l - 2 , k);

        ans %= z;

        ans += 10 * dp(l - 2 , k - 1);
    }

    memo[l][k] = ans % z;

    return memo[l][k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l , k;

    ll ans;

    cin >> t;

    memset(memo , -1 , sizeof(memo));

    while(t--)
    {
        cin >> l >> k;

        ans = dp(l , k);

        cout << ans << endl;
    }

    return 0;
}
