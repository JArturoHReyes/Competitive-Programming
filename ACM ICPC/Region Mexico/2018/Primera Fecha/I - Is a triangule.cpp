#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(false) , cin.tie(0);
#define in freopen("input.txt" , "r" , stdin);
#define out freopen("output.txt" , "w" , stdout);
#define endl '\n'
#define c(x) cout.precision(x) , cout << fixed;
#define tle cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
using namespace std;

int main()
{
    opt;

    int t;

    long long n , ans , c;

    cin >> t;

    while(t--)
    {
       cin >> n;

        c = n; n *= 2; n = sqrt(n); ans = n; n = n * (n + 1) / 2;

        if(c == n)
        {
            cout << ans << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;

}
