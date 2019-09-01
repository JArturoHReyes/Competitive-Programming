#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1010
using namespace std;

int t;

int n , c;

int w[maxn] , v[maxn];

int k[maxn][maxn];

int ks()
{
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= c; j++)
		{
			if(i == 0 || j == 0)
			{
				k[i][j] = 0;
			}
			else
			{
				if(w[i - 1] <= j)
				{
					k[i][j] = max(v[i - 1] + k[i - 1][j - w[i - 1]] , k[i - 1][j]);
				}
				else
				{
					k[i][j] = k[i - 1][j];
				}
			}
		}
	}

	return k[n][c];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << setprecision(5) << fixed;

	if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);

	cin >> t;

	while(t--)
	{
		cin >> c >> n;

		for(int i = 0; i < n; i++)
		{
			cin >> w[i] >> v[i];
		}

		cout << ks() << endl;
	}

	return 0;
}
