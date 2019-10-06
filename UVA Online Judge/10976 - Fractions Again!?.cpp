#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll n;

// 1 / k = (1 / x) + (1 / y)

// 1 / k = (x + y) / (x * y)

// k = (x * y) / (x + y)

// k = 10000 500 * 500 / 1000 250000 / 1000 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n)
    {
        vector < pair < ll , ll > > info;
        
        for(ll i = n + 1; i <= 2 * n; i++)
        {
            ll h = (i * n) / (i - n);
            
            ll ope = (h * i) / (h + i);
            
            if(ope == n)
            {
                info.push_back(make_pair(h , i));
            }
        }
        
        cout << info.size() << endl;
        
        for(auto t : info)
        {
            cout << "1/" << n << " = 1/" << t.first << " + 1/" << t.second << endl;
        }
    }
    
    return 0;
}
