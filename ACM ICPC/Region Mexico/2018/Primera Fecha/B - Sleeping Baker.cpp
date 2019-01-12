#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) , cout.precision(10);
#define in if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);
#define out freopen("output.txt" , "w" , stdout);
#define endl '\n'
#define tle cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#define ll long long
using namespace std;

int main()
{
    opt;

    ll m , n, i = 1 , sum , d;

    string x;

    while(cin >> m >> n)
    {
        vector < bitset < 2500 > > square (m);

        sum = 0;

        for(ll i = 0; i < m; i++)
        {
            cin >> x;

            square[i] = (bitset < 2500 >(x));
        }

        for(ll i = 0; i < m - 1; i++)
        {
            for(ll j = i + 1; j < m; j++)
            {
                d = (square[i] & square[j]).count();
                sum += (d * (d - 1) / 2);
            }
        }

        cout << "case " << i++ << ": " << sum << endl;

    }

    return 0;
}
