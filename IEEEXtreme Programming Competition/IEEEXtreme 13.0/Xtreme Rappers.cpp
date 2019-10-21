#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll mini , maxi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> mini >> maxi;
    
    if(maxi < mini)
    {
        swap(maxi , mini);
    }
    
    if(maxi >= mini * 2)
    {
        cout << mini << endl;
    }
    else
    {
        ll diff = maxi - mini;
        
        maxi -= diff * 2;
        
        diff += (2 * maxi / 3);
        
        cout << diff << endl;
    }
    
    return 0;
}
