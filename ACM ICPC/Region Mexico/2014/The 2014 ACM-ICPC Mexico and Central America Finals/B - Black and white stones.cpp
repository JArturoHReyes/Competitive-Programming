#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll ans , a , b;

string x;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(3) << fixed;

	if(fopen("in.txt", "r")) freopen("in.txt", "r", stdin);

	cin >> a >> b >> x;

	b = a - b;

	int i = 0 , j = x.length() - 1;

	while(true)
	{
		while(i < x.length() && x[i] == 'B')
		{
			i++;
		}

		while(j >= 0 && x[j] == 'W')
		{
			j--;
		}

		if(i >= j)
		{
			break;
		}

		ans += min(a , b * (j - i));

		i++ , j--;
	}

	cout << ans << endl;

 	return 0;
}
