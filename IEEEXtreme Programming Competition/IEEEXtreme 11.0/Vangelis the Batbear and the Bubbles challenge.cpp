#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1010
using namespace std;

vector < int > adj[maxn];

bool detectcycle(int actual , bool visited[] , int parent)
{
    visited[actual] = true;
    
    for(int i = 0; i < adj[actual].size(); i++)
    {
        int to = adj[actual][i];
        
        if(!visited[to])
        {
            if(detectcycle(to , visited , actual))
            {
                return true;
            }
        }
        else
        {
            if(to != parent)
            {
                return true;
            }
        }
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    
    int t , n , m , u , v;
    
    cin >> t;
    
    while(t--)
    {
        cin >> n >> m;
        
        bool *visited = new bool[n];
        
        for(int i = 0; i < n; i++)
        {
            visited[i] = false;
            adj[i].clear();
        }
        
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v;
            
            adj[u].push_back(v);
            
            adj[v].push_back(u);
        }
        
        bool iscycle = false;
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && detectcycle(i , visited , -1))
            {
                iscycle = true;
                break;
            }
        }
        
        if(iscycle)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }


	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
