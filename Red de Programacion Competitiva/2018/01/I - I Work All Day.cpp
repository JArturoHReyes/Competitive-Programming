#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;

int t;

int a[11];

int ans , mini;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> t;

    mini = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        if(mini > (t % a[i]))
        {
            mini = t % a[i];

            ans = a[i];
        }
    }

    cout << ans << endl;

    return 0;
}
