#include<bits/stdc++.h>
#define endl '\n'
#define maxn 2110
using namespace std;

struct edge
{
    int a , b , cap , flow , time;
};

vector < edge > e , e2;

vector < int > G[maxn];

vector < int > GasStations , Refineries;

int n , s , t , dist[maxn] , ptr[maxn] , q[maxn];

void add_edge(int a , int b , int cap)
{
   edge ea = {a , b , cap  , 0 , 0};
   edge eb = {b , a , 0 , 0 , 0};
   G[a].push_back((int) e.size());
   e.push_back(ea);
   G[b].push_back((int) e.size());
   e.push_back(eb);
}

void add_edgeh(int a , int b , int cap , int time)
{
    edge e1 = {a , b , cap , 0 , time};
    e2.push_back(e1);
}

void AddNormalEdges(int p , int r)
{
    for(int i = 1; i <= r; i++)
    {
        add_edge(s , i * 2 + 1 , Refineries[i - 1]);
    }

    for(int i = 1; i <= p; i++)
    {
        add_edge(i * 2 , t , GasStations[i - 1]);
    }
}

bool bfs()
{
    int height = 0 , totalnodes = 0;

    q[totalnodes++] = s;

    memset(dist , -1 , sizeof(dist));

    dist[s] = 0;

    while(height < totalnodes && dist[t] == -1)
    {
        int actualnode = q[height++];

        for(size_t i = 0; i < G[actualnode].size(); i++)
        {
            int id = G[actualnode][i];
            int to = e[id].b;

            if(dist[to] == -1 && e[id].flow < e[id].cap)
            {
                q[totalnodes++] = to;
                dist[to] = dist[actualnode] + 1;
            }
        }
    }

    return dist[t] != -1;
}

int dfs(int actual , int actualflow)
{
    if(!actualflow)
    {
        return 0;
    }

    if(actual == t)
    {
        return actualflow;
    }

    for(; ptr[actual] < (int) G[actual].size(); ptr[actual]++)
    {
        int id = G[actual][ptr[actual]];
        int to = e[id].b;

        if(dist[to] != dist[actual] + 1)
        {
            continue;
        }

        int pushed = dfs(to , min(actualflow , e[id].cap - e[id].flow));

        if(pushed)
        {
            e[id].flow += pushed;
            e[id ^ 1].flow -= pushed;
            return pushed;
        }
    }

    return 0;
}

int dinic()
{
    int flow = 0;

    while(true)
    {
        if(!bfs()) break;

        memset(ptr , 0 , sizeof(ptr));

        while(int pushed = dfs(s , INT_MAX))
        {
            flow += pushed;
        }
    }

    return flow;
}

void createGraph(int mid)
{
    e.clear();

    for(int i = 0; i < maxn; i++)
    {
        G[i].clear();
    }

    for(int i = 0; i < (int) e2.size(); i++)
    {
        if(e2[i].time <= mid)
        {
            add_edge(e2[i].a , e2[i].b , e2[i].cap);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);

    int p , r , c , TotalDemand = 0 , x , MaxTime = -1 , u , v , time;

    s = 0 , t = 1;

    cin >> p >> r >> c;

    for(int i = 0; i < p; i++)
    {
        cin >> x;

        TotalDemand += x;

        GasStations.push_back(x);
    }

    for(int i = 0; i < r; i++)
    {
        cin >> x;

        Refineries.push_back(x);
    }

    for(int i = 0; i < c; i++)
    {
        cin >> u >> v >> time;

        add_edgeh(v * 2 + 1 , u * 2 , INT_MAX , time);

        MaxTime = max(MaxTime , time);
    }

    int low = 0 , high = MaxTime;

    s = 0 , t = 1;

    createGraph(high);

    AddNormalEdges(p , r);

    if(dinic() != TotalDemand)
    {
        cout << -1 << endl;
        return 0;
    }

    while(low <= high)
    {
        int mid = (low + high) >> 1;

        createGraph(mid);

        AddNormalEdges(p , r);

        if(dinic() == TotalDemand)
        {
            high = mid - 1;
        }
        else
        {
           low = mid + 1;
        }
    }

    cout << high + 1 << endl;

    return 0;
}
