#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll z = 1e9 + 7;

int h , w , n;

ll ans , maxih;

ll dp[110][10010];

ll f(int pos , ll rem)
{
    if(pos == w)
    {
        return 1LL;
    }

    if(dp[pos][rem] != -1)
    {
        return dp[pos][rem];
    }

    if(rem == 0LL)
    {
        return dp[pos][rem] = 1;
    }

    ll ret = 0;

    for(int i = 0; i <= h; i++)
    {
        if(rem - i < 0) break;

        ret = ret + f(pos + 1 , rem - i) % z;
    }

    return dp[pos][rem] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp , -1 , sizeof(dp));

    cin >> n >> w >> h;

    ans = f(0 , n);

    maxih = min(n , w * h);

    maxih /= w;

    maxih++;

    ans = (ans - maxih + z) % z;

    cout << ans << endl;

    return 0;
}
