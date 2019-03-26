#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 100010
using namespace std;

int n , k , cnt;

ll a[maxn];

ll low , high , mid , sum , ans;

bool ok;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	while(cin >> n >> k)
	{
	    high = 0;
	    
	    low = 1e7;
	    
	    for(int i = 0; i < n; i++)
	    {
	        cin >> a[i];
	        
	        high += a[i];
	        
	        low = min(low , a[i]);
	    }
	    
	    while(low <= high)
	    {
	        mid = (low + high) >> 1;
	        
	        ok = true;
	        
	        cnt = 1;
	        
	        sum = 0;
	        
	        for(int i = 0; i < n; i++)
	        {
	            if(a[i] > mid)
	            {
	                ok = false;
	                
	                break;
	            }
	            
	            if(sum + a[i] <= mid)
	            {
	                sum += a[i];
	            }
	            else
	            {
	                sum = a[i];
	                
	                cnt++;
	            }
	        }
	        
	        if(cnt <= k && ok)
            {
                high = mid - 1;
                
                ans = mid;
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
