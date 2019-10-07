#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 30
using namespace std;

int t , n , k;

string x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    for(int cc = 1; cc <= t; cc++)
    {
        cin >> n >> k >> x;
        
        map < char , int > info;
        
        k++;
        
        k = min(k , n);
        
        int ans = 0;
        
        for(int i = 0; i < k; i++)
        {
            if(info[x[i]] > 0)
            {
                ans++;
            }
            
            info[x[i]]++;
        }
        
        for(int i = k; i < n; i++)
        {
            info[x[i - k]]--;
            
            if(info[x[i]] > 0)
            {
                ans++;
            }
            
            info[x[i]]++;
        }
        
        cout << "Case " << cc << ": " << ans << endl;
    }
    
    
    return 0;
}
