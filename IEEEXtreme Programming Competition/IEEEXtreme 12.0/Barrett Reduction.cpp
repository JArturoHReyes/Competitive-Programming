#include<bits/stdc++.h>
#define endl '\n'
#define ll unsigned long long
using namespace std;

ll a , b , low , high , mid , check , check2 , ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    cin >> a >> b;
    
    bool ok = true;
    
    high = (ll) pow(2 , 31);
    
    while(ok)
    {
        mid = (low + high) >> 1;
        
        check = mid * a >> b;
        
        if(check == 0)
        {
            low = mid;
        }
        else
        {
            if(check >= 2)
            {
                high = mid;
            }
            else
            {
                check2 = (mid - 1) * a >> b;
                
                if(check2 == 0)
                {
                    ok = false;
                    
                    ans = mid;
                    
                    break;
                }
                else
                {
                    high = mid;
                }
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
