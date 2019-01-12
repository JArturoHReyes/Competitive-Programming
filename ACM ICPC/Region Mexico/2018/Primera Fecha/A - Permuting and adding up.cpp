#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(false) , cin.tie(0);
#define in freopen("input.txt" , "r" , stdin);
#define out freopen("output.txt" , "w" , stdout);
#define endl '\n'
#define c(x) cout.precision(x) , cout << fixed;
#define tle cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#define ull unsigned long long
using namespace std;

ull factorial(ull a)
{
    if(a == 1)
    {
        return a;
    }

    return a * factorial(a - 1);
}

int main()
{
    opt;

    int t; ull sum , ncomb;

    string x;

    cin >> t;

    while(t--)
    {
        cin >> x;

        sum = 0;

        vector < int > freq(10 , 0);

        for(int i = 0; i < x.length(); i++)
        {
            freq[x[i] - '0']++;
        }

        ncomb = factorial(x.length());

        for(int i = 0; i < 10; i++)
        {
            if(freq[i] > 1)
            {
                ncomb /= factorial(freq[i]);
            }
        }

        cout << ncomb << " ";

        string ans = "";

        for(int i = 0; i < x.length(); i++)
        {
           for(int j = 1; j < 10; j++)
           {
               sum += j * freq[j] * ncomb / x.length();
           }

           //cout << sum % 10;

           ans += (sum % 10 + '0');

           sum /= 10;
        }

        while(sum)
        {
            //cout << sum % 10;

            ans += (sum % 10 + '0');

            sum /= 10;
        }

        for(int i = ans.length() - 1; i >= 0; i--)
        {
            cout << ans[i];
        }

        cout << endl;
    }

    return 0;

}
