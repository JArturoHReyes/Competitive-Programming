#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll a[100010];

ll v , fff;

int n , K;

ll low , high , mid , ans , ok , ret , val;

bool check() 
{ 
	int cnt = 1; 

	ll sum = 0ll; 

    ret = 0;

	for (int i = 0; i < n; i++) 
    { 
		if (a[i] > mid) 
        {
            return false;
        }

		sum += a[i]; 

		if (sum > mid) 
        {
            sum -= a[i];

            val = sum / v;

            val += (sum % v) != 0;

            ret = max(ret , val);

			cnt++; 

			sum = a[i]; 
		} 
	}

    val = sum / v;

    val += (sum % v) != 0;

    ret = max(ret , val);

	if (cnt <= K) 
    {
        return true; 
    }

	return false; 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextM.txt" , "r")) freopen("ArturoTextM.txt" , "r" , stdin);

	cin >> n >> K >> v;

    low = 1e18; high = 0ll;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];

        low = min(low , a[i]);

        high += a[i];
	}

    //cout << "low = " << low << " high = " << high << endl;

    ans = 1e18;

    while(low <= high)
    {
        mid = (low + high) / 2ll;

        if(check())
        {
            ans = ret;

            high = mid - 1ll;
        }
        else
        {
            low = mid + 1ll;
        }
    }

    cout << ans << endl;

    return 0;
} 
