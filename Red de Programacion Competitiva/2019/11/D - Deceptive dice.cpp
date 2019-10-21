#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n , k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(10) << fixed;

    cin >> n >> k;

    double ans = (n + 1) / 2.0;

    for(int i = 2; i <= k; i++)
    {
        int mini = floor(ans);

        ans = (mini * ans + (n - mini) * (n + mini + 1) / 2) / n;
    }

    cout << ans << endl;

    return 0;
}
