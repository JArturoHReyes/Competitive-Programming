#include<bits/stdc++.h>
#define endl '\n'
#define maxn 10010
#define ll long long
using namespace std;

int t , n , u , v , m;

ll c[maxn];

vector < int > adj[maxn];

bool visited[maxn];

ll sum;

void dfs(int actual)
{
    sum += c[actual];
    
    visited[actual] = true;
    
    for(int to : adj[actual])
    {
        if(!visited[to])
        {
            dfs(to);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    while(t--)
    {
        cin >> n >> m;
        
        for(int i = 0; i < n; i++)
        {
            cin >> c[i];
            
            adj[i].clear();
            
            visited[i] = false;
        }
        
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v;
            
            adj[u].push_back(v);
            
            adj[v].push_back(u);
        }
        
        bool possible = true;
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                sum = 0;
                
                dfs(i);
                
                if(sum != 0)
                {
                    possible = false;
                    
                    break;
                }
            }
        }
        
        if(possible)
        {
            cout << "POSSIBLE" << endl;
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    
    return 0;
}
