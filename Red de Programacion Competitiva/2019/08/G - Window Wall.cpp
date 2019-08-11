#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll w , h , d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextG.txt" , "r")) freopen("ArturoTextG.txt" , "r" , stdin);

    cin >> w >> h >> d;

    ll required = (2LL * w * d) - (2LL * h * d) + (4 * d * d);

    ll area = w * h;

    if(required > area)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << max(w * h - (2LL * w * d) - (2LL * h * d) + (4 * d * d), 0LL) << endl;
    }

    return 0;
}
