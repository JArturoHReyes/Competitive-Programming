#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(false) , cin.tie(0);
#define in freopen("input.txt" , "r" , stdin);
#define out freopen("output.txt" , "w" , stdout);
#define endl '\n'
#define c(x) cout.precision(x) , cout << fixed;
#define tle cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
using namespace std;

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

const long long z = 1e9 + 7;

int main()
{
    opt;

    long long n;

    map < long long , long long > ans;

    int t;

    cin >> t;

    while(t--)
    {
        cin >> n;

        if(ans[n])
        {
            cout << ans[n] << endl;
        }
        else
        {
            ans[n] = modpow(n , n + 1, z);
            ans[n] = (ans[n] - n + 1 + z) % z;
            cout << ans[n] << endl;
        }
    }


    return 0;

}
