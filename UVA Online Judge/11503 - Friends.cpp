#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

int t , n;

map < string , int > info;

string a[maxn] , b[maxn];

int p[maxn];

int f[maxn];

int idx;

int fin(int x)
{
    while(x != p[x])
    {
        x = p[x];
    }
    
    return x;
}

void unite(int x , int y)
{
    int px = fin(x);
    
    int py = fin(y);
    
    if(px != py)
    {
        p[py] = px;
        
        f[px] += f[py];
    }
    
    cout << f[px] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    while(t--)
    {
        cin >> n;
        
        info.clear();
        
        memset(p , 0 , sizeof(p));
        
        memset(f , 0 , sizeof(f));
        
        idx = 0;
        
        for(int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
            
            if(info.find(a[i]) == info.end())
            {
                p[idx] = idx;
                f[idx] = 1;
                info[a[i]] = idx++;
            }
            
            if(info.find(b[i]) == info.end())
            {
                p[idx] = idx;
                f[idx] = 1;
                info[b[i]] = idx++;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            unite(info[a[i]] , info[b[i]]);
        }
    }
    
    return 0;
}
