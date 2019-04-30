#include<bits/stdc++.h>
#define endl '\n'
#define maxn 10010
using namespace std;

vector < int > adj[maxn];

const int maxlogn = log2(maxn) + 1;

int n , u , v , q;

int parent[maxn][maxlogn] , level[maxn];

void dfs(int actual , int prev)
{
    level[actual] = level[prev] + 1;

    parent[actual][0] = prev;

    for(int to : adj[actual])
    {
        if(to != prev)
        {
            dfs(to , actual);
        }
    }
}

int lca(int x , int y)
{
    if(level[x] < level[y])
    {
        swap(x , y);
    }

    int loggy = log2(level[x]);

    for(int i = loggy; i >= 0; i--)
    {
        if(level[x] - level[y] >= (1 << i))
        {
            x = parent[x][i];
        }
    }

    if(x == y)
    {
        return x;
    }

    for(int i = loggy; i >= 0; i--)
    {
        if(parent[x][i] != -1 && parent[x][i] != parent[y][i])
        {
            x = parent[x][i];

            y = parent[y][i];
        }
    }

    return parent[x][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 1; i < n; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);

        adj[v].push_back(u);
    }

    memset(parent , -1 , sizeof(parent));

    level[0] = -1;

    dfs(1 , 0);

    for(int j = 1; j < maxlogn; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(parent[i][j - 1] != -1)
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }

    cin >> q;

    int x , y;

    while(q--)
    {
        cin >> x >> y;

        if(level[x] < level[y])
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES ";

            cout << lca(x , y) << endl;
        }
    }

    return 0;
}
