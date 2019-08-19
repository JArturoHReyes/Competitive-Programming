#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 210
#define maxb 10010
using namespace std;

int d , p , r , b , n , u , v , cc;

int a[maxn] , party[maxn] , w[maxn] , gain[maxn][2];

vector < int > adj[maxn];

bool visited[maxn];

int dp[maxb];

void bfs(int s)
{
	queue < int > q;

	q.push(s);

	gain[cc][party[s]] = -1;

	gain[cc][1 - party[s]] = 1;

	w[cc] = a[s];

	visited[s] = true;

	while(!q.empty())
	{
		int actual = q.front();

		q.pop();

		for(int to : adj[actual])
		{
			if(!visited[to])
			{
				visited[to] = true;

				q.push(to);

				w[cc] += a[to];

				gain[cc][party[to]]--;

				gain[cc][1 - party[to]]++;
			}
		}
	}

}

int go(int z)
{
	memset(dp , 0 , sizeof(dp));

	if(gain[0][z] > 0)
	{
		for(int i = w[0]; i <= b; i++)
		{
			dp[i] = gain[0][z];
		}
	}

	for(int i = 1; i < cc; i++)
	{
		if(gain[i][z] > 0)
		{
			for(int j = b; j >= w[i]; j--)
			{
				dp[j] = max(dp[j] , gain[i][z] + dp[j - w[i]]);
			}
		}
	}

	return dp[b];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << setprecision(5) << fixed;

	if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);

	
	while(cin >> d >> p >> r >> b)
	{
		n = d + p;

		memset(visited , false , sizeof(visited));

		for(int i = 0; i < n; i++)
		{
			adj[i].clear();
		}

		for(int i = 0; i < d; i++)
		{
			cin >> a[i];

			party[i] = 0;
		}

		for(int i = 0; i < p; i++)
		{
			cin >> a[d + i];

			party[d + i] = 1;
		}

		for(int i = 0; i < r; i++)
		{
			cin >> u >> v;

			u-- , v--;

			adj[u].push_back(d + v);

			adj[d + v].push_back(u);
		}

		cc = 0;

		for(int i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				bfs(i);

				cc++;
			}
		}

		cout << d + go(0) << " " << p + go(1) << endl;
	}
	

	return 0;
}
