#include<bits/stdc++.h>
#define endl '\n'
#define maxn 20010
using namespace std;

int n , t , u , v;

int p[maxn];

int r[maxn];

int parent(int x)
{
    while(x != p[x])
    {
        x = p[x];
    }
    
    return x;
}


void unite(int a , int b)
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < maxn; i++)
    {
        p[i] = i;
    }
    
    while(cin >> t >> u >> v)
    {
        if(t == 1)
        {
            if((parent(u) == parent(v + n)) or (parent(v) == parent(u + n)))
            {
                cout << -1 << endl;
            }
            else
            {
                unite(u , v);
                
                unite(u + n , v + n);
            }
        }
        
        if(t == 2)
        {
            if((parent(u) == parent(v)) or (parent(u + n) == parent(v + n)))
            {
                cout << -1 << endl;
            }
            else
            {
                unite(u , v + n);
                
                unite(v , u + n);
            }
        }
        
        if(t == 3)
        {
            if((parent(u) == parent(v)) or (parent(u + n) == parent(v + n)))
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        
        if(t == 4)
        {
            if((parent(u) == parent(v + n)) or (parent(v) == parent(u + n)))
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
    
    return 0;
}
