#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 200010
using namespace std;

ll memo[maxn][2] , a[maxn] , c;

bool visited[maxn][2];

int n;

ll dp(int i , bool o)
{
    if(i >= n)
    {
        return 0;
    }

    if(visited[i][o])
    {
        return memo[i][o];
    }

    visited[i][o] = true;

    ll ans = dp(i + 1 , o);

    if(o)
    {
        ans = max(ans , dp(i + 1 , false) + a[i]);
    }
    else
    {
        ans = max(ans , dp(i + 1 , true) - a[i] - c);
    }

    return memo[i][o] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n >> c)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];

            memo[i][0] = memo[i][1] = visited[i][0] = visited[i][1] = 0;
        }

        cout << dp(0 , false) << endl;
    }

    return 0;
}
