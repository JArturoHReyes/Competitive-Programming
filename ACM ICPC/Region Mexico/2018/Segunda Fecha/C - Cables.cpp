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

    int t , cables , totalcables , minimo , low , high , mid , cablesmid , ans;

    while(cin >> t)
    {
        while(t--)
        {
            cin >> cables >> totalcables;

            vector < int > allcables(cables);

            minimo = 0;

            for(int i = 0; i < cables; i++)
            {
                cin >> allcables[i];

                minimo = max(minimo , allcables[i]);
            }

            low = 0;

            high = minimo;

            ans = 0;

            while(low <= high)
            {
                mid = (low + high + 1) / 2;

                if(mid == 0) break;

                cablesmid = 0;

                for(int i = 0; i < cables && cablesmid < totalcables; i++)
                {
                    cablesmid += (allcables[i] / mid);
                }

                if(cablesmid >= totalcables)
                {
                    ans = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }

            }

            cout << ans << endl;
        }
    }

    return 0;
}
