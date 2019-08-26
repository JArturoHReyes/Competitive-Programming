#include<bits/stdc++.h>
#define endl '\n'
#define maxn 10010
using namespace std;

vector < int > adj[maxn];

int c[maxn];

int n , m , u , v;

int gcd(int a , int b)
{
	if(!b)
	{
		return a;
	}

	return gcd(b , a % b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(3) << fixed;

	if(fopen("in.txt", "r")) freopen("in.txt", "r", stdin);

	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}

	for(int i = 0; i < m; i++)
	{
		cin >> u >> v;

		adj[u].push_back(v);

		adj[v].push_back(u);
	}

	queue < pair < int , int > > q;

	unordered_set < int > ans;

	set < pair < int , int > > states;

	for(int i = 1; i <= n; i++)
	{
		auto t = make_pair(i , c[i]);

		q.push(t);

		states.insert(t);

		ans.insert(c[i]);
	}

	while(!q.empty())
	{
		auto t = q.front();

		q.pop();

		int actual = t.first , actualc = t.second;

		for(int to : adj[actual])
		{
			int g = gcd(c[to] , actualc);

			auto t = make_pair(to , g);

			if(!states.count(t))
			{
				q.push(t);

				ans.insert(g);

				states.insert(t);
			}
		}
	}

	cout << ans.size() << endl;

 	return 0;
}
