#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

double ans;

int n , x;

map < int , double > lol;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(4) << fixed;

    lol[0] = 2.0;

    lol[1] = 1.0;

    lol[2] = 0.5;

    lol[4] = 0.25;

    lol[8] = 0.125;

    lol[16] = lol[8] / 2;

    cin >> n;

    while(n--)
    {
        cin >> x;

        ans += lol[x];
    }

    cout << ans << endl;

    return 0;
}
