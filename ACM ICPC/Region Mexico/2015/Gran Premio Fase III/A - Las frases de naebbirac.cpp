#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string x , y;

int t;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> x >> y;

        int ans = 0;

        for(int i = 0; i < x.length(); i++)
        {
            ans += (x[i] != y[i]);
        }

        cout << ans << endl;
    }

    return 0;
}
