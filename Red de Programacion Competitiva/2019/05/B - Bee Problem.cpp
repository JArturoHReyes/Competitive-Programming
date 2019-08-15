#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1010
using namespace std;

int h , n , m , ans;

string square[maxn][maxn];

bool visited[maxn][maxn];

int dx[] = {0 , 1 , 0 , -1 , 1 , -1};

int dy[] = {1 , 0 , -1 , 0 , 0};

int bfs(int i , int j)
{
	int ret = 1;

	visited[i][j] = true;

	queue < pair < int , int > > q;

	q.push(make_pair(i , j));

	while(!q.empty())
	{
		auto t = q.front();

		q.pop();

		for(int x = 0; x < 4; x++)
		{
			int xx = t.first + dx[x];

			int yy = t.second + dy[x];

			if(min(xx , yy) >= 0 && xx < n && yy < m && square[xx][yy] != "#" && !visited[xx][yy])
			{
				visited[xx][yy] = true;

				ret++;

				q.push(make_pair(xx , yy));
			}
		}

		if(t.first & 1)
		{
			dy[4] = 1;
		}
		else
		{
			dy[4] = -1;
		}

		for(int x = 4; x < 6; x++)
		{
			int xx = t.first + dx[x];

			int yy = t.second + dy[4];

			if(min(xx , yy) >= 0 && xx < n && yy < m && square[xx][yy] != "#" && !visited[xx][yy])
			{
				visited[xx][yy] = true;

				ret++;

				q.push(make_pair(xx , yy));
			}
		}
	}

	return ret;
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);

	cin >> h >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> square[i][j];
		}
	}
	
	vector < int > areas;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(square[i][j] != "#" && !visited[i][j])
			{
				areas.push_back(bfs(i , j));
			}
		}
	}

	sort(areas.rbegin() , areas.rend());

	for(int aa : areas)
	{
		if(h > 0)
		{
			h -= aa;
			ans++;
		}
		else
		{
			break;
		}
	}

	cout << ans << endl;

	return 0;

}
