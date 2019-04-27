#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int t , c;

ll n , ans;

ll go()
{
    ll ret = 0;

    for(ll i = 1; i * (i + 1) < 2 * n; i++)
    {
        ll d = n - (i * (i + 1) / 2);

        if(d % (i + 1) == 0)
        {
            ret = max(ret , d / (i + 1));

            return ret;
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // n & (n - 1) is to ask if n is a power of two

    cin >> t;

    while(t--)
    {
        cin >> n;

        ans = 0;

        if(n & 1)
        {
            ans = n / 2ll;
        }
        else
        {
            ans = go();
        }

        cout << "case " << ++c << ": " << ans ? ans : -1 << endl;
    }

    return 0;
}
