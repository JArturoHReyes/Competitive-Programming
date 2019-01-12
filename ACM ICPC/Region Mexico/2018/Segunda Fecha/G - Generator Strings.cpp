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

    unsigned long long t , n , ans; string x;

    while(cin >> t)
    {
        while(t--)
        {
           cin >> n;

           map < vector < int > , int > freq;

           ans = n;

           while(n--)
           {
              cin >> x;

              vector < int > letters(26 , 0);

              for(int i = 0; i < x.length(); i++)
              {
                letters[x[i] - 'a']++;
              }

              freq[letters]++;
           }

           for(auto it = freq.begin(); it != freq.end(); it++)
           {
               if(it->second > 1)
               {
                   ans += ((it->second - 1) * it->second);
               }
           }

           cout << ans << endl;
        }
    }

    return 0;

}
