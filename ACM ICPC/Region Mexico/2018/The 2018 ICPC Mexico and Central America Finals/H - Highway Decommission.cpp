#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 10010
using namespace std;

struct edge
{
    int to;

    ll len , cost;

    bool operator < (const edge &otheredge) const
    {
        if(len == otheredge.len)
        {
            return cost > otheredge.cost;
        }

        return len > otheredge.len;
    }
};

int cmp(const edge &a , const edge &b)
{
    if(a < b)
    {
        return 1;
    }

    if(b < a)
    {
        return -1;
    }

    return 0;
}

int n , m , u , v;

ll l , c , ans;

vector < edge > adj[maxn];

ll costs[maxn];

void dijkstra()
{
    priority_queue < edge > q;

    q.push({0 , 0 , 0});

    vector < edge > best(n , {0 , LLONG_MAX , LLONG_MAX});

    best[0] = {0 , 0 , 0};

    while(!q.empty())
    {
        edge actual = q.top();

        q.pop();

        int nextnode = actual.to;

        if(cmp(actual , best[nextnode]) == 1) // actual edge is worse than the best edge for the nextnode
        {
            continue;
        }

        for(edge nextedge : adj[nextnode])
        {
            int node = nextedge.to;

            edge extra = {node , actual.len + nextedge.len , nextedge.cost};

            if(cmp(extra , best[node]) == -1)
            {
                best[node] = extra;

                costs[node] = nextedge.cost;

                q.push(extra);
            }
        }
    }


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> l >> c;

        u-- , v--;

        adj[u].push_back({v , l , c});

        adj[v].push_back({u , l , c});
    }

    dijkstra();

    for(int i = 0; i < n; i++)
    {
        ans += costs[i];
    }

    cout << ans << endl;

    return 0;
}
