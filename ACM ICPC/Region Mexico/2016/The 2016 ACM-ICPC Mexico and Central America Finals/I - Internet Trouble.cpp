#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 6010
using namespace std;

int n;

ll b , c;

ll a[maxn];

ll sum[maxn];

ll cost[maxn];

ll g[maxn][maxn];

ll dp[maxn][maxn];

void go(int k , int l , int r , int optl , int optr)
{
	if(l > r)
	{
		return;
	}

	int mid = (l + r) >> 1;

	dp[mid][k] = 1ll << 62;

	int best = -1;

	int e = min(optr , mid - 1);

	for(int i = optl; i <= e; i++)
	{
		ll val = 0;

		if(mid == n)
		{
			val = dp[i][k - 1] + g[i + 1][n];
		}
		else
		{
			val = dp[i][k - 1] + g[i + 1][mid - 1];
		}

		if(dp[mid][k] > val)
		{
			dp[mid][k] = val;

			best = i;
		}
	}

	go(k , l , mid - 1 , optl , best);

	go(k , mid + 1 , r , best , optr);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << setprecision(10) << fixed;

	if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);

	cin >> n >> b >> c;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];

		sum[i + 1]  = sum[i] + a[i];

		cost[i + 1] = cost[i] + (ll) a[i] * i;
	}

	// create the graph, how many houses are from i to j (including i)

	for(int i = n - 1; i >= 0; i--)
	{
		g[i][i] = a[i];

		for(int j = i + 1; j < n; j++)
		{
			g[i][j] = sum[j + 1] - sum[i] + g[i + 1][j - 1];
		}
	}

	for(int i = 0; i < n; i++)
	{
		dp[i][0] = (ll) (i * sum[i]) - cost[i];
	}

	for(int i = n - 1; i >= 0; i--)
	{
		g[i][n] = sum[n] - sum[i] + g[i + 1][n];
	}

	for(int k = 1; k <= n; k++)	
	{
		go(k , 0 , n , k - 1 , n - 1);

		ll ans = dp[n][k] * c + (ll) k * b;

		cout << ans;

		if(k != n)
		{
			cout << " ";
		}
	}

	cout << endl;

	return 0;
}
