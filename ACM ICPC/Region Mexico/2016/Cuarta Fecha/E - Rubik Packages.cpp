#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n && n)
    {
        ll i = 1 , ans = 0;

        for(; i * i * i <= n; i++)
        {
            if(n % (i * i * i) == 0)
            {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
