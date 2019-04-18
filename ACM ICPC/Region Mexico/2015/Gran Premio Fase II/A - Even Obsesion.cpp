#include<bits/stdc++.h>
#define endl '\n'
#define maxn 10010
#define inf 100000000000000000LL
#define ll long long
using namespace std;

int n , m , u , v;

vector < pair < int , ll >  > adj[maxn];

ll w , ans;

ll dist[maxn][2];

struct situation
{
    int actual;

    ll d;

    int parity;

    bool operator < (const situation &o) const
    {
        return d > o.d;
    }
};


void dijkstra()
{
    priority_queue < situation > Q;

    situation now , after;

    now.actual = 1;

    now.d = 0;

    now.parity = 0;

    dist[1][0] = 0;

    Q.push(now);

    while(!Q.empty())
    {
        now = Q.top();

        Q.pop();

        for(auto to : adj[now.actual])
        {
            if(dist[to.first][(now.parity + 1) % 2] > dist[now.actual][now.parity % 2] + to.second)
            {
                after.d = dist[to.first][(now.parity + 1) % 2] = dist[now.actual][now.parity % 2] + to.second;

                after.actual = to.first;

                after.parity = now.parity + 1;

                Q.push(after);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n >> m)
    {
        for(int i = 0; i <= n; i++)
        {
            adj[i].clear();

            dist[i][0] = inf;

            dist[i][1] = inf;
        }

        for(int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;

            adj[u].emplace_back(v , w);

            adj[v].emplace_back(u , w);
        }

        dijkstra();

        ans = dist[n][0];

        if(ans == inf)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }

    return 0;
}
