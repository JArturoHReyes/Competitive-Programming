#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string x;

ll ans , sum;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(3) << fixed;

	if(fopen("in.txt", "r")) freopen("in.txt", "r", stdin);

	cin >> x;

	for(int i = 0; i < x.length(); i++)
	{
		if(!isalpha(x[i]))
		{
			int j = i;

			while(j + 1 < x.length() && !isalpha(x[j + 1]))
			{
				j++;
			}

			sum = 0;

			vector < ll > cnt(3 , 0);

			for(int k = i; k <= j; k++)
			{
				sum = (sum + (x[k] - '0')) % 3;
				
				cnt[sum]++;
			}

			/*cout << "cnt 0 = " << cnt[0] << endl;

			cout << "cnt 1 = " << cnt[1] << endl;

			cout << "cnt 2 = " << cnt[2] << endl; */

			ans += cnt[0] + cnt[0] * (cnt[0] - 1) / 2;

			ans += cnt[1] * (cnt[1] - 1) / 2;

			ans += cnt[2] * (cnt[2] - 1) / 2;

			i = j;
		}
	}

	cout << ans << endl;

 	return 0;
}
