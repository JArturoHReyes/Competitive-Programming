#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1010
using namespace std;

string x;

int cnt[10] , s , e , d;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << setprecision(5) << fixed;

	if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);

	
	while(cin >> x)
	{
		memset(cnt , 0 , sizeof(cnt));

		vector < int > ans;

		e = x.length();

		s = e;

		for(int i = 0; i < e; i++)
		{
			d = x[i] - '0';

			ans.push_back(d);

			if(++cnt[d] > 2)
			{
				while(true)
				{
					bool ok = false;

					d = x[i] - '0';

					cnt[d]--;

					ans.pop_back();

					for(int k = d - 1; k >= 0; k--)
					{
						if(cnt[k] < 2)
						{
							ans.push_back(k);

							cnt[k]++;

							ok = true;

							break;
						}
					}

					if(ok)
					{
						break;
					}

					i--;
				}

				s = i + 1;

				break;
			}
		}

		for(int i = s; i < e; i++)
		{
			for(int k = 9; k >= 0; k--)
			{
				if(cnt[k] < 2)
				{
					ans.push_back(k);

					cnt[k]++;

					break;
				}
			}
		}

		if(ans[0] != 0)
		{
			cout << ans[0];
		}

		for(int i = 1; i < e; i++)
		{
			cout << ans[i];
		}

		cout << endl;
	}

	return 0;
}
