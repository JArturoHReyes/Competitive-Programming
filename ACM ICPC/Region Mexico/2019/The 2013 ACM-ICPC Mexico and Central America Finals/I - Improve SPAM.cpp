#include<bits/stdc++.h>
#define endl '\n'
#define maxn 2010
#define ll long long
using namespace std;

int ans = 0;

vector < int > adj[maxn];

int n , m , k , u;

ll dp[maxn];

const ll z = 1e9 + 7;

ll dfs(int actual)
{
    if(dp[actual])
    {
        return dp[actual];
    }
    
    if(adj[actual].size() == 0)
    {
        ans++;
        dp[actual] = 1;
    }
    
    for(int to : adj[actual])
    {
        dp[actual] += dfs(to);
        
        dp[actual] %= z;
    }
    
    return dp[actual];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for(int i = 1; i <= m; i++)
    {
        cin >> k;
        
        while(k--)
        {
            cin >> u;
            
            adj[i].push_back(u);
        }
    }
    
    cout << dfs(1) << " " << ans << endl;
    
    return 0;
}
