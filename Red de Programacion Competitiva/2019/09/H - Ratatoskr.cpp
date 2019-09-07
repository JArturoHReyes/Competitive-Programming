#include<bits/stdc++.h>
#define endl '\n'
#define maxn 110
using namespace std;

int n , u , v;

int p[3];

vector < int > adj[maxn];

queue < int > q;

int deg[maxn];

int h[maxn];

int c1 , c2;

int hmax;

bool reach[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextH.txt" , "r")) freopen("ArturoTextH.txt" , "r" , stdin);

    cin >> n;

    for(int i = 0; i < 3; i++)
    {
        cin >> p[i];
    }

    for(int i = 1; i < n; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);

        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
    {
        deg[i] = adj[i].size();

        if(deg[i] == 1)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int actual = q.front();

        q.pop();

        c1 = c2;

        c2 = actual;

        for(int to : adj[actual])
        {
            --deg[to];

            if(deg[to] == 1)
            {
                h[to] = h[actual] + 1;

                q.push(to);
            }
        }
    }

    q.push(p[0]);

    while(!q.empty())
    {
        int actual = q.front();

        q.pop();

        if(actual == p[1] or actual == p[2])
        {
            continue;
        }

        reach[actual] = true;

        hmax = max(hmax , h[actual]);

        for(int to : adj[actual])
        {
            if(!reach[to])
            {
                q.push(to);
            }
        }
    }

    if(h[c1] == h[c2] && reach[c1] && reach[c2])
    {
        hmax++;
    }

    cout << hmax + 1 << endl;

    return 0;
}
