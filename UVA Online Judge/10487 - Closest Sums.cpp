#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1010
using namespace std;

int n , m , e , c;

ll a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    c = 1;
    
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        sort(a , a + n);
        
        cin >> m;
        
        cout << "Case " << c++ << ":" << endl;
        
        while(m--)
        {
            ll ans = a[0] , diff = 1e18;
            
            cin >> e;
            
            int le = 0;
            
            int ri = n - 1;
            
            while(le < ri)
            {
                ll sum = a[le] + a[ri];
                
                if(abs(e - sum) < diff)
                {
                    diff = abs(e - sum);
                    
                    ans = sum;
                }
                
                if(sum == e)
                {
                    break;
                }
                
                if(sum < e)
                {
                    le++;
                }
                
                if(sum > e)
                {
                    ri--;
                }
            }
            
            cout << "Closest sum to " << e << " is " << ans << "." << endl;
        }
    }
    
    return 0;
}
