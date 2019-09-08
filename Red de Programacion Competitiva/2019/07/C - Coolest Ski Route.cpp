#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1010
using namespace std;

int n , m , u , v;

vector < pair < int , ll > > adj[maxn];

int indeg[maxn];

queue < int > q;

ll dp[maxn];

ll c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextC.txt" , "r")) freopen("ArturoTextC.txt" , "r" , stdin);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;

        adj[u].push_back(make_pair(v , c));

        indeg[v]++;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!indeg[i])
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int actual = q.front();

        q.pop();

        for(auto t : adj[actual])
        {
            int to;

            ll d;

            tie(to , d) = t;

            dp[to] = max(dp[actual] + d , dp[to]);

            --indeg[to];

            if(!indeg[to])
            {
                q.push(to);
            }
        }
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++)
    {
        ans = max(ans , dp[i]);
    }

    cout << ans << endl;

    return 0;
}
