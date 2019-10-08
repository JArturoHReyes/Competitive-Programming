#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 10010
using namespace std;

int n , k;

ll a[maxn];

bool can(ll actual)
{
    int cnt = 1;
    
    ll sum = 0;
    
    for(int i = 0; i < n; i++)
    {
        sum += a[i];
        
        if(actual < a[i])
        {
            return false;
        }
        
        if(sum > actual)
        {
            cnt++;
            
            sum = a[i];
        }
    }
    
    return cnt <= k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n >> k)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        ll low = 1 , high = 1e10 , ans;
        
        while(low <= high)
        {
            ll mid = (low  + high) / 2;
            
            if(can(mid))
            {
                ans = mid;
                
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
