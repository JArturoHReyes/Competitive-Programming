#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll n , m , T , tu , r;

ll actual , days , ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextI.txt" , "r")) freopen("ArturoTextI.txt" , "r" , stdin);

    ans = 1e18;

    cin >> n >> m >> T >> tu >> r;

    for(ll i = 1; i <= n; i++)
    {
        if(actual + tu <= T)
        {
            actual += tu;

            days++;

            if(days == m)
            {
                ans = min(ans , i);
            }
        }
        else
        {
            actual -= r;

            actual = max(actual , 0LL);
        }
    }

    if(ans != 1e18)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
