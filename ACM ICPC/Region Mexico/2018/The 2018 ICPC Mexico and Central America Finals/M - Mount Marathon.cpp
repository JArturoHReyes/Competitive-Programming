#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int n , ans;

int a[100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(8) << fixed;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for(int i = n - 1; i >= 0; i--)
    {
        int prev = a[i] , cnt = 1;
        
        for(int j = i - 1; j >= 0; j--)
        {
            if(prev <= a[j])
            {
                prev = a[j];
                
                cnt++;
            }
            else
            {
                break;
            }
        }
        
        if(cnt == 1)
        {
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
