#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string have , want;

ll k;

map < char , ll > infohave , infowant;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);

	cin >> have >> k >> want;

	bool readfirstdigit = false;

	char prev = '?';

	ll i = 1;

	for(char c : have)
	{
		if(isalpha(c))
		{
			infohave[prev] += i;

			prev = c;

			i = 1;

			readfirstdigit = true;
		}
		else
		{
			if(readfirstdigit)
			{
				readfirstdigit = false;

				i = 0;
			}

			i *= 10;

			i += (ll)(c - '0');
		}
	}

	infohave[prev] += i;

	readfirstdigit = false;

	i = 1;

	prev = '?';

	for(char c : want)
	{
		if(isalpha(c))
		{
			infowant[prev] += i;

			prev = c;

			i = 1;

			readfirstdigit = true;
		}
		else
		{
			if(readfirstdigit)
			{
				readfirstdigit = false;

				i = 0;
			}

			i *= 10;

			i += (ll)(c - '0');
		}
	}

	infowant[prev] += i;

	ll ans = 1e18;

	for(auto it = infowant.begin(); it != infowant.end(); it++)
	{
		if(it->first != '?')
		{
			ans = min(ans , infohave[it->first] * k / it->second);
		}
	}

	cout << ans << endl;

	return 0;

}
