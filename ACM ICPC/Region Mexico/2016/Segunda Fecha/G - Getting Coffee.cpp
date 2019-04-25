#include<bits/stdc++.h>
#define endl '\n'
#define maxn 110
#define ll long long
using namespace std;

int n , m , u , v;

struct Edge
{
    int to;

    ll cost;

    bool operator < (const Edge &o) const
    {
        return cost > o.cost || (cost == o.cost && to < o.to);
    }
};

vector < Edge > adj[maxn];

ll dist[maxn];

ll c;

int parent1[maxn] , parent2[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n >> m)
    {
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();

            dist[i] = 1e18;
        }

        for(int i = 0; i < m; i++)
        {
            cin >> u >> v >> c;

            adj[u].push_back(Edge{v , c});

            adj[v].push_back(Edge{u , c});
        }

        queue < Edge > q;

        dist[1] = 0;

        q.push(Edge{1 , 0});

        while(!q.empty())
        {
            int actual = q.front().to;

            q.pop();

            for(Edge nextedge : adj[actual])
            {
                int nodeadj = nextedge.to;

                ll nextcost = nextedge.cost;

                if(dist[nodeadj] > dist[actual] + nextcost)
                {
                    dist[nodeadj] = dist[actual] + nextcost;

                    parent1[nodeadj] = actual;

                    q.push(Edge{nodeadj , dist[nodeadj]});
                }
            }
        }

        memset(parent2 , -1 , sizeof(parent2));

        int source = n;

        ll dist1 = dist[n];

        while(source != 1)
        {
            parent2[source] = parent1[source];

            source = parent1[source];
        }

        q.push(Edge{1 , 0});

        for(int i = 1; i <= n; i++)
        {
            dist[i] = 1e18;
        }

        dist[1] = 0;

        while(!q.empty())
        {
            int actual = q.front().to;

            q.pop();

            for(Edge nextedge : adj[actual])
            {
                int nodeadj = nextedge.to;

                ll nextcost = nextedge.cost;

                if(parent2[nodeadj] == actual)
                {
                    continue;
                }

                if(parent2[actual] == nodeadj)
                {
                    nextcost = -nextcost; // continue;
                }

                if(dist[nodeadj] > dist[actual] + nextcost)
                {
                    dist[nodeadj] = dist[actual] + nextcost;

                    q.push(Edge{nodeadj , dist[nodeadj]});
                }
            }
        }

        cout << dist1 + dist[n] << endl;
    }

    return 0;
}
