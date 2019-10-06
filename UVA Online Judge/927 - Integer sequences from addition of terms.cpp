#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 30
using namespace std;

int t , n;

ll a[maxn] , d , k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    while(t--)
    {
        cin >> n;
        
        for(int i = 0; i <= n; i++)
        {
            cin >> a[i];
        }
        
        cin >> d >> k;
        
        ll sum = 0;
        
        for(int c = 1; c <= k; c++)
        {
            sum += c * d;
            
            if(sum >= k)
            {
                ll ans = 0;
                
                for(int i = 0; i <= n; i++)
                {
                    ans += a[i] * pow(c , i);
                }
                
                cout << ans << endl;
                
                break;
            }
        }
    }
    
    return 0;
}
