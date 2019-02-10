#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

struct node
{
    int u , v , d;

    node(int _u , int _v , int _d)
    {
        u = _u , v = _v , d = _d;
    }

    node()
    {

    }

};

int nodes , edges;

vector < pair < int , int > > adj[maxn];

int uf[maxn];

bool visited[maxn];

int parent[maxn];

int M[maxn];

int levels[maxn];

int P[maxn][18];

int Maximum[maxn][18];

void getTree(int actual , int level)
{
    visited[actual] = true;

    levels[actual] = level;

    for(int i = 0; i < adj[actual].size(); i++)
    {
        if(!visited[adj[actual][i].first])
        {
            M[adj[actual][i].first] = adj[actual][i].second;

            parent[adj[actual][i].first] = actual;

            getTree(adj[actual][i].first , level + 1);
        }
    }

}

void getParent()
{
    memset(P , -1 , sizeof(P));

    for(int i = 0; i < nodes; i++)
    {
        P[i][0] = parent[i];

        Maximum[i][0] = M[i];
    }

    for(int j = 1; (1 << j) < nodes; j++)
    {
        for(int i = 1; i < nodes; i++)
        {
            if(P[i][j - 1] != -1)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];
                Maximum[i][j] = max(Maximum[i][j - 1] , Maximum[P[i][j - 1]][j - 1]);
            }
        }
    }

    return;
}

int LCA(int a , int b)
{
    if(levels[a] < levels[b])
    {
        swap(a , b);
    }

    for(int i = 16; i >= 0; i--)
    {
        if(levels[a] - (1 << i) >= levels[b])
        {
            a = P[a][i];
        }
    }

    if(a == b)
    {
        return a;
    }

    for(int i = 16; i >= 0; i--)
    {
        if(P[a][i] != P[b][i])
        {
            a = P[a][i];
            b = P[b][i];
        }
    }

    return parent[a];
}

bool operator < (node a , node b)
{
    if(a.d != b.d)
    {
        return a.d < b.d;
    }

    if(a.u != b.u)
    {
        return a.u < b.u;
    }

    return a.v < b.v;
}

int finder(int x)
{
    if(uf[x] == x)
    {
        return x;
    }
    else
    {
        return uf[x] = finder(uf[x]);
    }
}

int maxim(int a , int b)
{
    int dev = 0;

    for(int i = 16; i >= 0; i--)
    {
        if(levels[a] - levels[b] >= (1 << i))
        {
            dev = max(dev , Maximum[a][i]);
            a = P[a][i];
        }
    }

    return dev;
}

void unioncomponent(int x , int y)
{
    uf[finder(x)] = finder(y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);

    freopen("in.txt" , "r" , stdin);

    cin >> nodes >> edges;

    nodes++;

    for(int i = 1; i < nodes; i++)
    {
        uf[i] = i;
    }

    vector < node > v;

    map < pair < int , int > , int > m;

    int sum = 0 , queries;

    for(int i = 0; i < edges; i++)
    {
        int a , b , d;

        cin >> a >> b >> d;

        v.emplace_back(node(a , b , d));

        m[make_pair(a , b)] = d;
    }

    sort(v.begin() , v.end());

    for(int i = 0; i < edges; i++)
    {
        if(finder(v[i].u) != finder(v[i].v))
        {
            unioncomponent(v[i].u , v[i].v);

            adj[v[i].u].emplace_back(v[i].v , v[i].d);
            adj[v[i].v].emplace_back(v[i].u , v[i].d);

            sum += v[i].d;
        }
    }

    memset(parent , -1 , sizeof(parent));

    getTree(1 , 1);

    getParent();

    cin >> queries;

    while(queries--)
    {
        int a , b;

        cin >> a >> b;

        int x = LCA(a , b);

        int val = m[make_pair(a , b)];

        cout << sum + val - max(maxim(a , x) , maxim(b , x)) << endl;
    }

    return 0;

}
