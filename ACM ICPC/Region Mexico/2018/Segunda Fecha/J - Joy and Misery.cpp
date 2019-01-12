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

    int t , x , y;

    cin >> t;

    while(t--)
    {
        cin >> x >> y;

        int diff = (y - x) / 2 + 1;

        if(x != y)
        {
            if(x & 1 && y & 1)
            {
               cout << diff - 1 << " " << diff << endl;
            }
            else
            {
                if(x % 2 == 0 && y % 2 == 0)
                {
                    cout << diff << " " << diff  - 1 << endl;
                }
                else
                {
                    cout << diff << " " << diff << endl;
                }
            }
        }
        else
        {
            if(x & 1)
            {
                cout << "0 1" << endl;
            }
            else
            {
                cout << "1 0" << endl;
            }
        }
    }

    return 0;
}
