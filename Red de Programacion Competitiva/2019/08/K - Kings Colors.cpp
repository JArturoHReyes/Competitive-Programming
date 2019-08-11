#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 2510
using namespace std;

ll n , k;

ll dp[maxn][maxn];

const ll z = 1e9 + 7;

ll rec(int pos , ll u)
{
    if(pos == n)
    {
        return u == k;
    }

    ll &ret = dp[pos][u];

    if(ret != -1)
    {
        return ret;
    }

    ret = 0;

	if (u > 1)
    {
        (ret += rec(pos + 1, u) * 1LL * (u - 1LL) % z) %= z;
    }

	if (u < k)
    {
        (ret += rec(pos + 1, u + 1LL) * 1LL * (k - u) % z) %= z;
    }

	return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextK.txt" , "r")) freopen("ArturoTextK.txt" , "r" , stdin);

    cin >>  n >> k;

    memset(dp , -1 , sizeof(dp));

    cout << rec(0 , 0) << endl;

    return 0;
}
