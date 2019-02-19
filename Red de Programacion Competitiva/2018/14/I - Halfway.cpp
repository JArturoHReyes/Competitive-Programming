#include<bits/stdc++.h>
#define endl '\n'
#define ll unsigned long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextI.txt" , "r")) freopen("ArturoTextI.txt" , "r" , stdin);

    ll n;

    cin >> n;

    n--;

    ll total = n * (n + 1ULL) / 2ULL;

    //cout << "total = " << total << endl;

    ll check = (total + 1ULL) / 2ULL;

    //cout << "check = " << check << endl;

    ll low = 1ULL , high = n , ans = 0ULL , mid , cmp;

    while(low <= high)
    {
        mid = (low + high) / 2ULL;

        //cout << "mid = " << mid << endl;

        cmp = (n - mid) * ((n - mid) + 1ULL) / 2ULL;

        cmp = total - cmp;

        //cout << "comparisons made = " << cmp << endl;

        if(cmp >= check)
        {
            ans = mid;
            high = mid - 1ULL;
        }
        else
        {
            low = mid + 1ULL;
        }
    }

    if(ans == 0ULL)
    {
        cout << 1 / 0 << endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}
