#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

int level[maxn], deg[maxn], parent[maxn];

vector < int > adj[maxn];

int u , v , n, ans;

void dfs(int actual , int prev, int lev)
{
    level[actual] = lev;

    for(int to : adj[actual])
    {
        if(to != prev)
        {
            dfs(to, actual, lev + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    parent[1] = -1;

    for(int i = 2; i <= n; i++)
    {
        cin >> parent[i];

        deg[parent[i]]++;

        adj[i].push_back(parent[i]);

        adj[parent[i]].push_back(i);
    }

    dfs(1, -1, 0);

    // You are sorting by the greatest level

    set < pair < int , int > > E;

    for(int i = 2; i <= n; i++)
    {
        E.insert({-level[i], i});
    }

    while(!E.empty())
    {
        auto e = *E.begin();

        E.erase(E.begin());

        int actual = e.second;

        int par_act = parent[actual];

        pair < int , int > aux = {-level[par_act], par_act};

        if(deg[actual] >= 2 && deg[par_act] >= 3 && par_act != 1 && (E.find(aux) != E.end()))
        {
            E.erase(aux);

            ans++;

            deg[parent[par_act]]--;
        }
    }

    cout << ans << endl;

    return 0;
}
