#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[5] , b[5];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(3) << fixed;

	if(fopen("in.txt", "r")) freopen("in.txt", "r", stdin);

	for(int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}

	for(int i = 0; i < 5; i++)
	{
		cin >> b[i];
	}

	bool ok = true;

	for(int i = 0; i < 5; i++)
	{
		if(a[i] == b[i])
		{
			ok = false;

			break;
		}
	}

	if(ok)
	{
		cout << "Y" << endl;
	}
	else
	{
		cout << "N" << endl;
	}

 	return 0;
}
