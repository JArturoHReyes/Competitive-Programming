#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1010
using namespace std;

int t , n;

ll a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    while(t--)
    {
        cin >> n;
        
        ll sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            
            for(int j = 0; j < i; j++)
            {
                sum += (a[i] >= a[j]);
            }
        }
        
        cout << sum << endl;
    }
    
    return 0;
}
