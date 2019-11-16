#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string x;

int n;

ll ans , s;

ll corte, e;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x >> s;

	n = x.length();

	x += x;

	for(corte = 0; corte < n; corte++)
	{
		while(e < x.length())
		{
			if(e >= corte && x[e] == 'E') break;
			e++;
		}

		ans += max(0ll , s - (e - corte));
	}

	cout << ans << endl;

	return 0;
}
