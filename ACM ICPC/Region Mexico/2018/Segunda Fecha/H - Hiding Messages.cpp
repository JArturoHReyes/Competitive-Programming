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

    int t , n , k;

    string x;

    cin >> t;

    getline(cin , x);

    while(t--)
    {
        cin >> n >> k;

        getline(cin  , x);

        k %= 26;

        while(n--)
        {
            getline(cin , x);

            for(int i = 0; i < x.length(); i++)
            {
                if(isupper(x[i]))
                {

                    int ope = (int) x[i] + k;

                    if(ope >= 26 + 'A')
                    {
                        ope -= 26;
                    }
                    cout << (char) ope;
                }
                else
                {
                    cout << x[i];
                }
            }

            cout << endl;
        }
    }

    return 0;
}
