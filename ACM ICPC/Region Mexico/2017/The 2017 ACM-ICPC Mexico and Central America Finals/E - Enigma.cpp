#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1010
using namespace std;

string s;

int k;

int memo[maxn][maxn];

const int MOD = 1e9 + 7;

bool ispossible(int pos , int mod)
{
	if(pos == s.size())
	{
	    return (mod == 0);
	}

	if(memo[pos][mod] != -1)
	{
	    return memo[pos][mod];
	}

	int ret = 0;

	if(s[pos] == '?')
    {
		for(int i = 0; i < 10; i++)
		{
			if(pos == 0 && i == 0)
			{
			    continue;
			}

			ret = ret | ispossible(pos + 1 , (mod * 10 + i) % k);
		}
	}
	else
    {
        ret = ret | ispossible(pos + 1 , (mod * 10 + (s[pos] - '0')) % k);
	}

	memo[pos][mod] = ret;

	return ret;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> s >> k)
    {
		
    memset(memo,-1,sizeof(memo));

		if(!ispossible(0,0))
    {
			cout<<"*"<<endl;
		}
		else
    {
			string ans = "";

			int mod = 0;

			for(int i = 0; i < s.size(); i++)
            {
				if(s[i] == '?')
                {
					for(int j = 0; j < 10; j++)
                    {
						if(i == 0 && j == 0)
						{
						    continue;
						}
						if(ispossible(i + 1 , (mod * 10 + j) % k))
                        {
							mod = (mod * 10 + j) % k;
							ans += '0' + j;
							break;
						}
					}
				}
				else
                {
					ans += s[i];
					mod = (mod * 10 + (s[i] - '0')) % k;
				}
			}

			cout << ans << endl;
		}

	}

	return 0;
}
