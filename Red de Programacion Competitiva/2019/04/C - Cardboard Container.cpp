#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll v , ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextF.txt" , "r")) freopen("ArturoTextF.txt" , "r" , stdin);

    cin >> v;

    ans = 1e18;

    for(ll a = 1; a * a <= v; a++)
    {
        for(ll b = 1; b <= a; b++)
        {
            ll c = v / (a * b);

            if(a * b * c == v)
            {
                ans = min(ans , 2 * (a * b + b * c + c * a));
            }
        }
    }

    cout << ans << endl;

    return 0;
}
