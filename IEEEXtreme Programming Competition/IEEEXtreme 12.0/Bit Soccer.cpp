#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
#define ll long long
using namespace std;

int n , q;

ll a[maxn] , goal , ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(3) << fixed;

	if(fopen("in.txt", "r")) freopen("in.txt", "r", stdin);

    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    cin >> q;
    
    while(q--)
    {
        cin >> goal;
        
        ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            if((a[i] | goal) == goal)
            {
                ans |= a[i];
            }
        }
        
        if(ans == goal)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
	
 	return 0;
}
