#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

int n , g , s , r , ans;

int d[maxn];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(3) << fixed;

	if(fopen("in.txt", "r")) freopen("in.txt", "r", stdin);

	while(cin >> n >> g)
	{
		ans = 0;
		
		for(int i = 0; i < n; i++)
		{
			cin >> s >> r;

			d[i] = s - r;
		}

		sort(d , d + n);

		for(int i = n - 1; i >= 0; i--)
		{
			while(g && d[i] <= 0)
			{
				g--;
				d[i]++;
			}

			if(d[i] > 0)
			{
				ans += 3;
			}
			else if(d[i] == 0)
			{
				ans++;
			}
		}

		cout << ans << endl;
	}


 	return 0;
}
