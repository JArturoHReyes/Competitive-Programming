#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 200010
using namespace std;

ll t[maxn * 4];

int n , e;

void modify(int p , ll v)
{
    for(t[p += n] = v; p > 1; p >>= 1)
    {
        t[p >> 1] = t[p] + t[p ^ 1];
    }
}

ll query(int l , int r)
{
    ll res = 0;

    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            res += t[l++];
        }

        if (r & 1)
        {
            res += t[--r];
        }
    }

    return res;
}

string x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int cases = 1 , le , ri, pos;
    
    ll val;
    
    cin >> n;
    
    while(n)
    {
        cout << "Case " << cases++ << ":" << endl;
        
        for(int i = 0; i < n; i++)
        {
            cin >> e;
            
            modify(i , e);
        }
        
        while(cin >> x && x != "END")
        {
            if(x == "M")
            {
                cin >> le >> ri;
                
                cout << query(le - 1, ri) << endl;   
            }
            else
            {
                cin >> pos >> val;
                
                modify(pos - 1, val);
            }
        }
        
        cin >> n;
        
        if(n != 0)
        {
            cout << endl;
        }
    }
    
    return 0;
}
