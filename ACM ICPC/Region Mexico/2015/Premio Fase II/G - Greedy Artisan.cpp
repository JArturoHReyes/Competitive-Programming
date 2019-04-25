#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
#define ll long long
using namespace std;

int n , k , t;

pair < ll , ll > m[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(6) << fixed;

    while(cin >> n >> k && !(n == 0 && k == 0))
    {
        for(int i = 0; i < n; i++)
        {
            cin >> m[i].first >> m[i].second;
        }

        sort(m , m + n);

        ll sum = 0;

        double ans = 1e+30;

        for(int i = 0; i < n; i++)
        {
            if(i >= k - 1)
            {
                ans = min(ans , (double) sum * m[i].second / m[i].first + m[i].second);
            }
            else
            {
                sum += m[i].first;
            }
        }

        cout << "Case #" << ++t << ": " << ans << endl;
    }


    return 0;
}
