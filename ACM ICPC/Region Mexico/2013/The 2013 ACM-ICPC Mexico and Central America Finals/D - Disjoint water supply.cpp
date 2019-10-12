#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
#define maxv 1010
using namespace std;

int n , m , u , v , ans;

vector < int > adj[maxn];

int dp[maxv][maxv];

int rec(int x , int y)
{
	if(x == y)
	{
		return 0;
	}

	if(x == 1)
	{
		return 1;
	}

	if(dp[x][y] != -1)
	{
		return dp[x][y];
	}

	int ret = 0;

	for(int to : adj[y])
	{
		if(rec(min(x , to) , max(x , to)))
		{
			ret = 1;
			break;
		}
	}

	dp[x][y] = ret;

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(3) << fixed;

	if(fopen("in.txt", "r")) freopen("in.txt", "r", stdin);

	while(cin >> n >> m)
	{
		for(int i = 1; i <= n; i++)
		{
			adj[i].clear();
		}

		for(int i = 0; i < m; i++)
		{
			cin >> u >> v;

			adj[v].push_back(u);
		}

		ans = n - 1; // (1 , 2) (1 , 3) ... (1 , n)

		memset(dp , -1 , sizeof(dp));

		for(int i = 2; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				ans += rec(i , j);
			}
		}

		cout << ans << endl;
	}

 	return 0;
}
