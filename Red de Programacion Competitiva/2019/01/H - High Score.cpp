#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll ans;

ll f(ll a , ll b , ll c)
{
    return a * a + b * b + c * c + 7 * min(a , min(b , c));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);

    if(fopen("ArturoHIn.txt" , "r")) freopen("ArturoHIn.txt" , "r" , stdin);

    ll a , b , c , n , d;

    cin >> n;

    while(n--)
    {
        cin >> a >> b >> c >> d;

        ans = 0;

        for(ll i = 0; i <= min(1000LL , d); i++)
        {
            for(ll j = 0; (i + j) <= min(1000LL , d); j++)
            {
                ll k = d - i - j;

                ans = max(ans , f(a + i, b + j, c + k));
            }
        }

        ans = max(ans , f(a + d , b , c));

        ans = max(ans , f(a , b + d , c));

        ans = max(ans , f(a , b , c + d));

        cout << ans << endl;
    }



	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
