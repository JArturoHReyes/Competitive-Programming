#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1010
using namespace std;

string x;

int low , high , mid , ans , c;

int s[maxn];

bool ok;

bool can(int sz)
{
    for(int j = 0; j < sz; j++) s[j] = 1000;
    
    for(int i = 0; i < x.length(); i++)
    {
        sort(s , s + sz);
        
        ok = true;
        
        for(int j = 0; j < sz; j++)
        {
            if(s[j] >= x[i])
            {
                s[j] = x[i];
                
                ok = false;
                
                break;
            }
        }
        
        if(ok)
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> x && x != "end")
    {
        low = 1 , high = x.length();
        
        while(low <= high)
        {
            mid = (low + high) / 2;
             
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
        
        cout << "Case " << ++c << ": " << ans << endl;
    }
    
    return 0;
}
