#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100005
#define ll long long
using namespace std;

int n , f , a , b , c;

bool friends[maxn];

vector < pair < int , int > > adj[maxn] , out[maxn];

const ll inf = 1e18;

bool go(int actual)
{
	bool ans = false;

	for(auto to : adj[actual])
	{
		bool curr = go(to.first);

		if(curr)
		{
			out[actual].push_back(to);
		}

		ans = ans || curr;
	}

	return (ans || friends[actual]);
}

ll dfs2(int actual)
{
	ll ans = 0;

	for(auto to : out[actual])
	{
		ans += dfs2(to.first) + to.second;
	}

	return ans;
}

ll dfs(int actual)
{
	if(out[actual].size() == 0)
	{
		return 0;
	}
	else
	{
		if(out[actual].size() == 1)
		{
			return dfs(out[actual][0].first);
		}
		else
		{
			ll ans = inf , total = 0;

			for(auto to : out[actual])
			{
				ll ret = dfs2(to.first) + to.second;

				ll stay = dfs(to.first);

				total += ret;

				ans = min(ans , stay - ret);
			}

			return total + ans;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(3) << fixed;

	if(fopen("in.txt", "r")) freopen("in.txt", "r", stdin);

	cin >> n >> f;

	for(int i = 1; i < n; i++)
	{
		cin >> a >> b >> c;

		adj[a - 1].push_back(make_pair(b - 1 , c));
	}

	for(int i = 0; i < f; i++)
	{
		cin >> a;

		friends[a - 1] = true;
	}

	go(0);

	cout << dfs(0) << endl;

 	return 0;
}
