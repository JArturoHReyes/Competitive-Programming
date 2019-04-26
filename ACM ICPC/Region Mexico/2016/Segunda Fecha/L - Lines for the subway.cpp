#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
#define maxlogn 20
#define ll long long
using namespace std;

struct edge
{
    int to;

    ll hard , len;
};

struct data
{
    int id;

    ll hard , len;
};

vector < edge > adj[maxn];

int n , u , v , q;

ll h , l;

int level[maxn];

data mem[maxn][maxlogn];

void dfs(int actual , int prev , int actuallevel)
{
    level[actual] = actuallevel;

    for(edge nextedge : adj[actual])
    {
        if(nextedge.to != prev)
        {
            dfs(nextedge.to , actual , actuallevel + 1);

            mem[nextedge.to][0] = data{actual , nextedge.hard , nextedge.len};
        }
    }
}

data dp(int actual , int level)
{
    if(actual == -2)
    {
        return data{-2 , 0 , 0};
    }

    if(~mem[actual][level].id)
    {
        return mem[actual][level];
    }

    data t1 = dp(actual , level - 1);

    data t2 = dp(t1.id , level - 1);

    mem[actual][level].id = t2.id;

    mem[actual][level].len = t1.len + t2.len;

    mem[actual][level].hard = max(t1.hard , t2.hard);

    return mem[actual][level];
}

ll lca(int a , int b)
{
    if(level[a] < level[b])
    {
        swap(a , b);
    }

    int diff = level[a] - level[b] , c = 0;

    ll maxhard = 0 , sumlengths = 0;

    while(diff)
    {
        if(diff & 1)
        {
            data t = dp(a , c);

            a = t.id;

            sumlengths += t.len;

            maxhard = max(maxhard , t.hard);
        }

        diff >>= 1;

        c++;
    }

    if(a == b)
    {
        return sumlengths * maxhard;
    }

    c = maxlogn - 1;

    while(c >= 0)
    {
        data t1 = dp(a , c) , t2 = dp(b , c);

        if(t1.id != t2.id)
        {
            a = t1.id;

            b = t2.id;

            sumlengths += t1.len + t2.len;

            maxhard = max(maxhard , max(t1.hard , t2.hard));
        }

        c--;
    }

    sumlengths += mem[a][0].len + mem[b][0].len;

    maxhard = max(maxhard , max(mem[a][0].hard , mem[b][0].hard));

    return sumlengths * maxhard;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            adj[i].clear();
        }

        for(int i = 1; i < n; i++)
        {
            cin >> u >> v >> h >> l;

            u-- , v--;

            adj[u].push_back(edge{v , h , l});

            adj[v].push_back(edge{u , h , l});
        }

        memset(mem , -1 , sizeof(mem));

        dfs(0 , -1 , 0);

        mem[0][0] = data{-2 , 0 , 0};

        cin >> q;

        while(q--)
        {
            cin >> u >> v;

            u-- , v--;

            cout << lca(u , v) << endl;
        }
    }


    return 0;
}
