#include<bits/stdc++.h>
#define endl '\n'
#define maxn 300010
using namespace std;

int n , m , p;

int dp[maxn][11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextI.txt" , "r")) freopen("ArturoTextI.txt" , "r" , stdin);

    cin >> n >> m;

    for(int i = 0; i <= m; i++)
    {
        for(int t = 0; t <= n; t++)
        {
            dp[t][i] = -1e9;
        }
    }

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++)
    {
        cin >> p;

        dp[i][1] = max(dp[i - 1][m] + p , dp[i - 1][0]); // in time m + 1 we have used power, in time 0 we have not used nothing

        for(int t = 2; t <= m; t++)
        {
            dp[i][t] = dp[i - 1][t - 1];
        }

		dp[i][m] = max(dp[i - 1][m] , dp[i][m]);
    }

    int ans = 0;

    for(int i = 0; i <= m; i++)
    {
        ans = max(ans , dp[n][i]);
    }

    cout << ans << endl;

    return 0;
}
