#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 100010
using namespace std;

int n;

ll m;

pair < ll , ll > a[maxn];

ll check(ll days)
{
    ll ret = 0;

    for(int i = 0; i < n; i++)
    {
        ll inc = days * a[i].first - a[i].second;

        ret += max(0ll , inc);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextH.txt" , "r")) freopen("ArturoTextH.txt" , "r" , stdin);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    ll low = 0 , high = 1;

    while(check(high) < m)
    {
        high += high;
    }

    while(high - low > 1)
    {
        ll mid = (low + high) >> 1;

        if(check(mid) >= m)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    cout << high << endl;

    return 0;
}
