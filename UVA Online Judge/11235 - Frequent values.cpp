#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 100010
using namespace std;

int n , q;

int a[maxn] , s[maxn] , c[maxn];

map < int , int > info;

int t[4 * maxn];

int qa , qb;

void modify(int p , int v)
{
    for(t[p += n] = v; p > 1; p >>= 1)
    {
        t[p >> 1] = max(t[p], t[p ^ 1]);
    }
}

int query(int l , int r)
{
    int res = 0;

    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            res = max(res, t[l++]);
        }

        if (r & 1)
        {
            res = max(res, t[--r]);
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n)
    {
        if(n == 0) break;
        
        info.clear();
        
        memset(t , 0 , sizeof(t));
        
        cin >> q;
        
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            
            info[a[i]]++;
        }
        
        int prev = a[1] , idx = 1;
        
        c[1] = info[a[1]];
        
        s[1] = 1;
        
        modify(1 , c[1]);
        
        for(int i = 2; i <= n; i++)
        {
            c[i] = info[a[i]];
            
            if(prev != a[i])
            {
                idx = i;
                
                prev = a[i];
            }
            
            s[i] = idx;
            
            modify(i , c[i]);
        }
        
        while(q--)
        {
            cin >> qa >> qb;
            
            //cout << "new query qa = " << qa << " qb = " << qb << endl;
            
            if(a[qa] != a[qb])
            {
                int k = s[qa] + c[qa];
                
                //cout << "s = " << s[qa] << " c = " << c[qa] << endl;
                
                //cout << "k = " << k << endl;
                
                int cnt1 = k - qa;
                
                int cnt2 = qb - s[qb] + 1;
                
                int cnt3 = query(k , s[qb]);
                
               // cout << "cnt1 = " << cnt1 << " cnt2 = " << cnt2 << " cnt3 = " << cnt3 << endl;
                
                cout << max(cnt1 , max(cnt2 , cnt3)) << endl;
            }
            else
            {
                cout << qb - qa + 1 << endl;
            }
        }
        
        
    }
    
    return 0;
}
