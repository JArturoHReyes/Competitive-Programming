#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 10010
using namespace std;

int t , visited , n , m , u , v , source;

vector < pair < int , ll > > adj[maxn];

ll cost , w;

ll dist[maxn];

int parent[maxn];

void clean()
{
    visited = 0;

    cost = 0;

    for(int i = 0; i < n; i++)
    {
        adj[i].clear();

        dist[i] = parent[i] = -1;
    }
}

// Debemos validar que no hemos pasado por ahi antes
int validate(int actual , int to)
{
    if(parent[actual] == to)
    {
        return 1;
    }

    if(parent[actual] == -1)
    {
        return -1;
    }

    return validate(parent[actual] , to);
}

void dfs(int actual)
{
    visited++;

    for(auto to : adj[actual])
    {
        if(dist[to.first] == -1)
        {
            cost += to.second;

            dist[to.first] = to.second;

            parent[to.first] = actual;

            dfs(to.first);
        }
        else
        {
            if(dist[to.first] > to.second)
            {
                if(validate(actual , to.first) == -1)
                {
                    cost -= (dist[to.first] - to.second);

                    dist[to.first] = to.second;

                    parent[to.first] = actual;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> source;

        clean();

        for(int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;

            adj[u].emplace_back(v , w);
        }

        dfs(source);

        if(visited == n)
        {
            cout << cost << endl;

            for(int i = 0; i < n; i++)
            {
                if(i != source)
                {
                    cout << parent[i] << " " << i << " " << dist[i] << endl;
                }
            }
        }
        else
        {
            cout << "impossible" << endl;
        }
    }


    return 0;
}
