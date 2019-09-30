#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

int n , m , k , pre , actual;

vector < int > adj[maxn];

int p[maxn];

int r[maxn];

int ans;

int parent(int x)
{
    while(x != p[x])
    {
        x = p[x];
    }
    
    return x;
}

bool same(int a , int b)
{
    return parent(a) == parent(b);
}

void unite(int a , int b)
{
    if(!same(a , b))
    {
        int pa = parent(a);
        
        int pb = parent(b);
        
        if(r[pa] > r[pb])
        {
            p[pb] = pa;
        }
        else
        {
            p[pa] = pb;
            
            if(r[pa] == r[pb])
            {
                r[pb]++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0) break;
        
        for(int i = 0; i < n; i++)
        {
            r[i] = 0;
            
            p[i] = i;
        }
        
        ans = 0;
        
        for(int i = 0; i < m; i++)
        {
            cin >> k;
            
            if(k)
            {
                cin >> pre;
                
                for(int i = 1; i < k; i++)
                {
                    cin >> actual;
                    
                    unite(actual , pre);
                    
                    pre = actual;
                }
            }
        }
        
        for(int i = 1; i < n; i++)
        {
            ans += same(0 , i);
        }
        
        cout << ans + 1 << endl;
    }
    
    return 0;
}
