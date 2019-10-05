#include<bits/stdc++.h>
#define endl '\n'
#define maxn 510
using namespace std;

int n , m , q;

int x , y, ansmin, ansmax;

char t;

int a[maxn] , maxi[maxn][maxn * 3] , mini[maxn][maxn * 3];

void maketree(int row, int column, int l, int r)
{
    if(l == r)
    {
        maxi[row][column] = mini[row][column] = a[l];
        
        return;
    }
    
    int mid = (l + r) / 2;
    
    int c = column + column;
    
    maketree(row, c, l, mid);
    
    maketree(row, c + 1, mid + 1, r);
    
    maxi[row][column] = max(maxi[row][c] , maxi[row][c + 1]);
    
    mini[row][column] = min(mini[row][c] , mini[row][c + 1]);
}

void update(int row, int column, int l, int r, int val)
{
    if(y == l && l == r)
    {
        maxi[row][column] = mini[row][column] = val;
        
        return;
    }
    
    if(y < l || r < y) return;
    
    int mid = (l + r) / 2;
    
    int c = column + column;
    
    update(row, c, l, mid, val);
    
    update(row, c + 1, mid + 1, r, val);
    
    maxi[row][column] = max(maxi[row][c] , maxi[row][c + 1]);
    
    mini[row][column] = min(mini[row][c] , mini[row][c + 1]);
}

void query(int row, int column, int l, int r) 
{
    if (r < x || y < l) return;
    
    if (x <= l && r <= y) 
    {
        ansmax = max(ansmax, maxi[row][column]);
        
        ansmin = min(ansmin, mini[row][column]);
        
        return;
    }
    
    int mid = (l + r) / 2, c = column + column;
    
    query(row, c, l, mid);
    
    query(row, c + 1, mid + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> a[j];
                
                maketree(i , 1 , 1 , n);
            }
        }
        
        m = n;
        
        cin >> q;
        
        int val, r1, r2;
        
        while(q--)
        {
            cin >> t;
            
            if(t == 'c')
            {
                cin >> x >> y >> val;
                
                update(x , 1 , 1 , m, val);
            }
            else
            {
                cin >> r1 >> x >> r2 >> y;
                
                ansmax = -1e9 , ansmin = 1e9;
                
                for(int i = r1; i <= r2; i++)
                {
                    query(i , 1 , 1 , m);
                }
                
                cout << ansmax << " " << ansmin << endl;
            }
        }
    }
    
    return 0;
}
