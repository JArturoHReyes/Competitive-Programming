#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

int t[maxn * 4];

int n , e , k , pos;

char tq;

void modify(int p , int v)
{
    for(t[p += n] = v; p > 1; p >>= 1)
    {
        t[p >> 1] = t[p] * t[p ^ 1];
    }
}

int query(int l , int r)
{
    int res = 1;

    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            res *= t[l++];
        }

        if (r & 1)
        {
            res *= t[--r];
        }
    }

    return res;
}

int change(int f)
{
    if(f < 0)
    {
        return -1;
    }
    
    if(f > 0)
    {
        return 1;
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n >> k)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> e;
            
            modify(i , change(e));
        }
        
        while(k--)
        {
            cin >> tq >> pos >> e;
            
            if(tq == 'C')
            {
                modify(pos - 1, change(e));
            }
            else
            {
                int res = query(pos - 1 , e);
                
                if(res < 0)
                {
                    cout << "-";
                }
                else
                {
                    if(res == 0)
                    {
                        cout << 0;
                    }
                    else
                    {
                        cout << "+";
                    }
                }
            }
        }
        
        cout << endl;
    }
    
    
    return 0;
}
