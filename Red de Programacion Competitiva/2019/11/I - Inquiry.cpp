#include<bits/stdc++.h>
#define endl '\n'
#define ll unsigned long long
#define maxn 1000010
using namespace std;

ll a[maxn] , dp[maxn] , dpm[maxn] , maxi , fi , la;

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];

        dp[i] = a[i];

        dpm[i] = a[i] * a[i];

        dp[i] += dp[i - 1];

        dpm[i] += dpm[i - 1];
    }

    maxi = a[1] * a[1] * a[n];

    for(int i = 1; i < n; i++)
    {
        fi = dpm[i];

        la = dp[n] - dp[i];

        maxi = max(maxi , la * fi);
    }

    cout << maxi << endl;

    return 0;
}
