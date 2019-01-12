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

    int t , n;

    cin >> t;

    while(t--)
    {
        cin >> n;

        if(n == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            int mod = 1;

            int digits = 1;

            for(; digits <= 1e6 && mod; digits++)
            {
                mod *= 10;
                mod += 1;
                mod %= n;
            }

            if(mod)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << digits << endl;
            }
        }
    }

    return 0;
}
