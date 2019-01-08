#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

long long n , k , dp[1005][1005] , m[1005][1005] , ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    
    if(fopen("in.txt" , "r"))
    {
    	//freopen("in.txt" , "r" , stdin);
	}
	
	cin >> n >> k;
	
	for(long long i = 1; i <= n; i++)
	{
	    for(long long j = 1; j <= n; j++)
	    {
	        cin >> m[i][j];
	        
	        if(m[i][j] >= k)
	        {
	            ans++;
	        }
	        
	        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + m[i][j];
	        
	        if(i > 1)
	        {
	            long long sum = 0 , low = 1 , high = i , mid;
	            
	            while(low <= high)
    	        {
    	            mid = (low + high + 1) / 2;
    	            
    	            if(mid == 0 || min((i - mid - 1) , (j - mid - 1)) < 0)
    	            {
    	                high = mid - 1;
    	            }
    	            else
    	            {
    	                if(dp[i][j] - dp[i - mid - 1][j] - dp[i][j - mid - 1] + dp[i - mid - 1][j - mid - 1] >= k)
    	                {
    	                    sum = min(i - mid , j - mid);
    	                   // cout << "lx = " << (i - mid) << " ly = " << (j - mid) << " ux = " << i << " uy = " << j << " ans = " << ans << endl;
                            high = mid - 1;
    	                }
    	                else
    	                {
    	                    low = mid + 1;
    	                }
    	            }
    	        }
    	        
    	        ans += sum;
	        }
	    }
	}
	
	cout << ans << endl;
	
	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
		
    return 0;
}
