#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

string x , y , z;

int ans;

map < int , int > dp[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextD.txt" , "r")) freopen("ArturoTextD.txt" , "r" , stdin);

    cin >> x >> y;

    dp[0][0] = -1;

    for(int i = 1; i <= x.length(); i++)
    {
        for(int j = 1; j <= i; j++)
        {
            string st = x.substr(j - 1 , i - j + 1);

            vector < int > masks;

			for (int s = 0; s + i - j < y.length(); s++)
			{
				if (y.substr(s , i - j + 1) == st)
				{
					masks.emplace_back(((1 << (i - j + 1)) - 1) << s);
				}
			}

			for (int mask : masks)
			{
				for (auto it : dp[j - 1])
				{
					if (it.first & mask)
                    {
                        continue;
                    }

					int newmask = it.first | mask;

					auto dit = dp[i].find(newmask);

					if (dit == dp[i].end())
                    {
                        dp[i][newmask] = it.second + 1;
                    }
					else
                    {
                        dp[i][newmask] = min(dit->second, it.second + 1);
                    }
				}
			}
        }
    }

    cout << dp[x.length()][(1 << x.length()) - 1]<<endl;

    return 0;
}
