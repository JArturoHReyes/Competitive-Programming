#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1010
using namespace std;

int n , m , u , v , A , B;

vector < pair < int , pair < int , int > > > adj[maxn];

const double inf = 1e12;

struct node
{
	int actual;

	double d;

	node(){}

	node(int _actual , double _d)
	{
		actual = _actual;
		d = _d;
	}
};

bool operator < (node a , node b)
{	
	if(a.d != b.d)
	{
		return a.d > b.d;
	}

	return a.actual < b.actual;
}

double dist[maxn];

double dijkstra(double t)
{
	for(int i = 2; i <= n; i++)
	{
		dist[i] = inf;
	}

	dist[1] = 0.0;

	priority_queue < node > q;

	q.push(node(1 , 0.0));

	while(!q.empty())
	{
		node x = q.top();

		q.pop();

		int act = x.actual;

		double di = x.d;

		for(auto to : adj[act])
		{
			if(dist[to.first] > dist[act] + (to.second.first * t + to.second.second))
			{
				dist[to.first] = dist[act] + (to.second.first * t + to.second.second);

				q.push(node(to.first , dist[to.first]));
			}
		}
	}

	return dist[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << setprecision(5) << fixed;

	if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);

	while(cin >> n >> m)
	{
		double low = 0.0 , high = 1440.0;

		for(int i = 1; i <= n; i++)
		{
			adj[i].clear();
		}

		for(int i = 0; i < m; i++)
		{
			cin >> u >> v >> A >> B;

			adj[u].push_back(make_pair(v , make_pair(A , B)));

			adj[v].push_back(make_pair(u , make_pair(A , B)));

			if(A > 0 && B < 0)
			{
				low = max(low , -(double)  B/A);
			}

			if(A < 0 && B > 0)
			{
				high = min(high , -(double) B/A);
			}
		}

		for(int z = 0; z < 100; z++)
		{
			double mid1 = (2 * low + high) / 3;

			double mid2 = (low +  2 * high) / 3;

			if(dijkstra(mid1) < dijkstra(mid2))
			{
				low = mid1;
			}
			else
			{
				high = mid2;
			}
		}

		cout << dijkstra(low) << endl;
	}


	return 0;
}
