#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1100000
using namespace std;

enum{ CLR = 0 , ZERO  , ONE , FLIP};

int t, lines, n , q;

string p;

int a[maxn];

int tree[maxn * 4] , lazy[maxn * 4];

char tq;

void build(int at, int l , int r)
{
    lazy[at] = CLR;
    
    if(l == r)
    {
        tree[at] = a[l];
        
        return;
    }
    
    int mid = (l + r) >> 1;
    
    build(at << 1 , l , mid);
    
    build(at << 1 | 1, mid + 1, r);
    
    tree[at] = tree[at << 1] + tree[at << 1 | 1];
}

int doflip(int x)
{
    if(x == ZERO)
    {
        return ONE;
    }
    
    if(x == ONE)
    {
        return ZERO;
    }
    
    if(x == CLR)
    {
        return FLIP;
    }
    
    return CLR;
}

void propagate(int at, int x, int y)
{
    if(lazy[at] == CLR) return;
    
    if(lazy[at] == ONE)
    {
        tree[at] = y - x + 1;
    }
    else if (lazy[at] == ZERO)
    {
        tree[at] = 0;
    }
    else if (lazy[at] == FLIP)
    {
        tree[at] = y - x + 1 - tree[at];
    }
    
    if(x != y)
    {
        if(lazy[at] == ONE || lazy[at] == ZERO ) 
        {
            lazy[at << 1] = lazy[at << 1 | 1] = lazy[at];
        } 
        else 
        {
            lazy[at << 1] = doflip(lazy[at << 1]);
            
            lazy[at << 1 | 1] = doflip(lazy[at << 1 | 1]);
        }
    }
    
    lazy[at] = CLR;
}

int query(int at, int l, int r, int x, int y)
{
    if(lazy[at] != CLR)
    {
        propagate(at, l, r);
    }
    
    if(l > y || x > r) return 0;
    
    if(l >= x && r <= y)
    {
        return tree[at];
    }
    
    int mid = (l + r) / 2;
    
    int q1 = query(at << 1, l , mid, x , y);
    
    int q2 = query(at << 1 | 1, mid + 1, r, x , y);
    
    return q1 + q2;
}

/* Set all the values to 1 */
void update1(int at, int l, int r, int x, int y)
{
    if( lazy[at] != CLR )
    {
        propagate(at, l, r);
    }

    if(l > y || x > r) return;

    if(l >= x && r <= y) 
    {
        tree[at] = r - l + 1;
        
        lazy[at << 1] = lazy[at << 1 | 1] = ONE;
        
        return;
    }
    
    int mid = (l + r) / 2;
    
    update1(at << 1, l, mid, x, y);
    
    update1(at << 1 | 1, mid + 1, r, x, y);
    
    tree[at] = tree[at << 1] + tree[at << 1 | 1];
}

/* Set all the values to 0 */
void update2(int at , int l , int r , int x , int y )
{
    if( lazy[at] != CLR )
    {
        propagate(at, l, r);
    }

    if(l > y || x > r) return;

    if(l >= x && r <= y) 
    {
        tree[at] = 0;
        
        lazy[at << 1] = lazy[at << 1 | 1] = ZERO;
        
        return ;
    }
    int mid = (l + r) / 2;
    
    update2(at << 1, l, mid, x, y);
    
    update2(at << 1 | 1, mid + 1, r, x, y);
    
    tree[at] = tree[at << 1] + tree[at << 1 | 1];
}

/* flip all the all values in range */
void update3(int at, int l, int r, int x, int y )
{

    if( lazy[at] != CLR )
    {
        propagate(at, l, r);
    }

    if(l > y || x > r) return;

    if(l >= x && r <= y)
    {
        tree[at] = r - l + 1 - tree[at];
        
        lazy[at << 1] = doflip(lazy[at << 1]);
        
        lazy[at << 1 | 1] = doflip(lazy[at << 1 | 1]);
        
        return;
    }
    
    int mid = (l + r) / 2;
    
    update3(at << 1, l, mid, x, y);
    
    update3(at << 1 | 1, mid + 1, r, x, y);
    
    tree[at] = tree[at << 1] + tree[at << 1 | 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int le, ri;
    
    cin >> t;
    
    for(int i = 1; i <= t; i++)
    {
        cin >> lines;
        
        int pos = 0;
        
        while(lines--)
        {
            cin >> n >> p;
            
            for(int j = 0; j < n; j++)
            {
                for(char c : p)
                {
                    a[pos++] = int(c - '0');
                }
            }
        }
        
        build(1 , 0 , pos - 1);
        
        cin >> q;
        
        cout << "Case " << i << ":" << endl;
        
        int qc = 1;
        
        while(q--)
        {
            cin >> tq >> le >> ri;
            
            if(tq == 'I')
            {
                update3(1, 0, pos - 1, le , ri);
            }
            
            if(tq == 'F')
            {
                update1(1, 0, pos - 1, le, ri);
            }
            
            if(tq == 'E')
            {
                update2(1, 0, pos - 1, le , ri);
            }
            
            if(tq == 'S')
            {
                cout << "Q" << qc++ << ": ";
                
                cout << query(1, 0, pos - 1, le, ri) << endl;
            }
        }
    }
    
    return 0;
}
