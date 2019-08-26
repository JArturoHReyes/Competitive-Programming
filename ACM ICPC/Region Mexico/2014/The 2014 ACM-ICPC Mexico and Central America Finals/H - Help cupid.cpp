#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n , a , ans;

int freq[100];

vector < int > b;

int go(int s)
{
	int actual = 0;

	for(int i = 0; i < b.size(); i += 2)
	{
		int ss = (i + s) % b.size();

		int ee = (i + s + 1) % b.size();

		actual += min(abs(b[ss] - b[ee]) , 24 - abs(b[ss] - b[ee]));
	}

	return actual;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(3) << fixed;

	if(fopen("in.txt", "r")) freopen("in.txt", "r", stdin);

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> a;

		a += 11;

		freq[a] ^= 1;
	}

	for(int i = 0; i <= 24; i++)
	{
		if(freq[i])
		{
			b.push_back(i - 11);
		}
	}

	if(b.empty())
	{
		cout << 0 << endl;

		return 0;
	}

	ans = 1e9;

	for(int i = 0; i < b.size(); i++)
	{
		ans = min(ans , go(i));
	}

	cout << ans << endl;

 	return 0;
}
