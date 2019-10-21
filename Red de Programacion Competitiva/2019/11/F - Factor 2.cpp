#include<bits/stdc++.h>
#define endl '\n'
#define maxn 5000010
using namespace std;

string x;

string y;

int dp[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x;

    y = "meow";

    for(int i = 0; i < 5 * (x.length() + 1); i++)
    {
        dp[i] = i % 5;
    }

    int ans = 4;

    for(int i = 0; i < x.length(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            // del , ins, rep

            dp[5 * (i + 1) + j + 1] = min(dp[5 * i + j + 1] + 1 , min(dp[5 * (i + 1) + j] + 1 , dp[5 * i + j] + (x[i] != y[j])));            

            if(i > 0 && j > 0)
            {
                if(x[i] == y[j - 1] && x[i - 1] == y[j])
                {
                    // swap
                    dp[5 * (i + 1) + j + 1] = min(dp[5 * (i + 1) + j + 1] , 1 + dp[5 * (i - 1) + j - 1]);
                }
            }
        }

        ans = min(ans , dp[5 * (i + 1) + 4]);
    }

    cout << ans << endl;

    return 0;
}
