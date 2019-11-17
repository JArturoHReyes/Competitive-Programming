#include<bits/stdc++.h>
#define endl '\n'
#define ll long double
using namespace std;

map < pair < int , int > , ll > dp;

int coins;

ll rec(int up , int flips)
{
    if(flips == 0)
    {
        return up;
    }

    if(!dp.count(make_pair(up , flips)))
    {
        ll sum = 0.0;

        if(up < coins)
        {
            sum = rec(up + 1 , flips - 1) + rec(up , flips - 1);
        }
        else
        {
            sum = rec(up , flips - 1) + rec(up - 1 , flips - 1);
        }

        dp[make_pair(up , flips)] = 0.5L * sum;
    }

    return dp[make_pair(up , flips)];
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(10) << fixed;

    int flips;

    cin >> coins >> flips;

    cout << abs(rec(0 , flips)) << endl;

    return 0;
}
