#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 100010
using namespace std;

int n;

ll x;

ll a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    cin >> n >> x;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1 , a + n + 1);

    int cnt = 1;

    for(int i = 2; i <= n; i++)
    {
        if(a[i] + a[i - 1] <= x)
        {
            cnt++;
        }
        else
        {
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}
