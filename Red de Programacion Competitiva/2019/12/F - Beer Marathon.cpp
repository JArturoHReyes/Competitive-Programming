#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1000010
using namespace std;

int n;

ll k , diff , ans;

ll a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a , a + n);

    for(int i = 0; i < n; i++)
    {
        a[i] -= diff;

        diff += k;
    }

    sort(a , a + n);

    ll mid = a[n / 2];

    for(int i = 0; i < n; i++)
    {
        ans += llabs(mid - a[i]);
    }

    cout << ans << endl;

    return 0;
}
