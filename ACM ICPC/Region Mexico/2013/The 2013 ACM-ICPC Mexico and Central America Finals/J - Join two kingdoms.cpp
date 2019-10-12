#include<bits/stdc++.h>
#define endl '\n'
#define ll double
#define maxn 40010
using namespace std;

vector < ll > adjn[maxn];

vector < ll > adjq[maxn];

int n , q , u , v;

ll disn[maxn] , disq[maxn]; // max dist from i to any node 

bool visited[maxn];

ll level[maxn] , dp[maxn];

pair < int , int > diameter(vector < ll > adj[maxn])
{
    memset(visited , false , sizeof(visited));
    
    queue < int > q;
    
    q.push(0);
    
    int s = 0;
    
    visited[s] = true;
    
    while(!q.empty())
    {
        s = q.front();
        
        q.pop();
        
        for(int to : adj[s])
        {
            if(!visited[to])
            {
                visited[to] = true;
                
                q.push(to);
            }
        }
    }
    
    int e = s;
    
    q.push(e);
    
    memset(visited , false , sizeof(visited));
    
    visited[e] = true;
    
    while(!q.empty())
    {
        e = q.front();
        
        q.pop();
        
        for(int to : adj[e])
        {
            if(!visited[to])
            {
                visited[to] = true;
                
                q.push(to);
            }
        }
    }
    
    return make_pair(s , e);
}

void filldisn(int actual)
{
    queue < int > q;
    
    q.push(actual);
    
    memset(visited , false , sizeof(visited));
    
    memset(level , 0 , sizeof(level));
    
    visited[actual] = true;
    
    while(!q.empty())
    {
        actual = q.front();
        
        disn[actual] = max(disn[actual] , level[actual]);
        
        q.pop();
        
        for(int to : adjn[actual])
        {
            if(!visited[to])
            {
                visited[to] = true;
                
                level[to] = level[actual] + 1;
                
                q.push(to);
            }
        }
    }
}

void filldisq(int actual)
{
    queue < int > q;
    
    q.push(actual);
    
    memset(visited , false , sizeof(visited));
    
    memset(level , 0 , sizeof(level));
    
    visited[actual] = true;
    
    while(!q.empty())
    {
        actual = q.front();
        
        disq[actual] = max(disq[actual] , level[actual]);
        
        q.pop();
        
        for(int to : adjq[actual])
        {
            if(!visited[to])
            {
                visited[to] = true;
                
                level[to] = level[actual] + 1;
                
                q.push(to);
            }
        }
    }
}

void bfs()
{
    memset(disn , 0 , sizeof(disn));
    
    memset(disq , 0 , sizeof(disq));
    
    pair < int , int > vdn = diameter(adjn);
    
    pair < int , int > vdq = diameter(adjq);
    
    filldisn(vdn.first);
    
    filldisn(vdn.second);
    
    filldisq(vdq.first);
    
    filldisq(vdq.second);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(3) << fixed;
    
    while(cin >> n >> q)
    {
        for(int i = 0; i < n; i++)
        {
            adjn[i].clear();
        }
        
        for(int i = 0; i < q; i++)
        {
            adjq[i].clear();
        }
        
        for(int i = 1; i < n; i++)
        {
            cin >> u >> v;
            
            u-- , v--;
            
            adjn[u].push_back(v);
            
            adjn[v].push_back(u);
        }
        
        for(int i = 1; i < q; i++)
        {
            cin >> u >> v;
            
            u-- , v--;
            
            adjq[u].push_back(v);
            
            adjq[v].push_back(u);
        }
        
        bfs();
        
        ll maxdist = 0;
        
        for(int i = 0; i < n; i++)
        {
            maxdist = max(maxdist , disn[i]);
        }
        
        for(int i = 0; i < q; i++)
        {
            maxdist = max(maxdist , disq[i]);
        }
        
        sort(disq , disq + q);
        
        dp[q - 1] = disq[q - 1];
        
        for(int i = q - 2; i >= 0; i--)
        {
            dp[i] = dp[i + 1] + disq[i];
        }
        
        ll ans = 0;
         
        for(int i = 0; i < n; i++)
        {
            int idx = lower_bound(disq , disq + q , maxdist - (disn[i] + 1)) - disq;
            
            ans += maxdist * idx;
            
            if(idx < q)
            {
                ans += dp[idx] + (disn[i] + 1) * (q - idx);
            }
        }
        
        cout << (double) (ans / (n * q)) << endl;
    }
    
    return 0;
}
