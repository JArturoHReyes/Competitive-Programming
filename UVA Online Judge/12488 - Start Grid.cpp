#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 30
using namespace std;

int n , e;

int a[maxn] , b[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n)
    {
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        
        for(int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        
        int ans = 0;
        
        for(int i = 1; i <= n; i++)
        {
            int j = i;
            
            for(; j <= n; j++)
            {
                if(a[j] == b[i])
                {
                    break;
                }
            }
            
            for(int k = j; k > i; k--)
            {
                a[k] = a[k - 1];
                
                ans++;
            }
        }
        
        cout << ans << endl;
    }
    
    
    return 0;
}
