#include<bits/stdc++.h>
#define endl '\n'
#define maxn 50010
using namespace std;

int n , x , y;

int lowx , highx , lowy , highy;

map < pair < int , int > , int > points;

vector < int > adj[maxn];

int color[maxn];

bool ok(pair < int , int > a , pair < int , int > b)
{
	int dist = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);

	return dist <= 25;
}

void dfs(int actual , int c)
{
	color[actual] = c;

	for(int to : adj[actual])
	{
		if(color[to] == -1)
		{
			dfs(to , 1 - c);
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

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;

		points[make_pair(x , y)] = i;
	}

	for(auto it = points.begin(); it != points.end(); it++)
	{
		x = it->first.first , y = it->first.second;

		lowx = max(1 , x - 5);

		lowy = max(1 , y - 5);

		highx = min(500001 , x + 5);

		highy = min(500001 , y + 5);

		for(int xx = lowx; xx <= highx; xx++)
		{
			for(int yy = lowy; yy <= highy; yy++)
			{
				 auto t = make_pair(xx , yy);

				 auto g = points.find(t);

				 if(ok(it->first , t) && g != points.end())
				 {
					 if(it->second != g->second)
					 {
						 adj[it->second].push_back(g->second);
					 }
				 }
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		color[i] = -1;
	}

	for(int i = 0; i < n; i++)
	{
		if(adj[i].size() > 0 && color[i] == -1)
		{
			dfs(i , 0);
		}
	}

	int r = 0 , b = 0;

	for(int i = 0; i < n; i++)
	{
		if(color[i] == 0)
		{
			r++;
		}
		else if(color[i] == 1)
		{
			b++;
		}
	}

	cout << min(r , b) << endl;

 	return 0;
}
