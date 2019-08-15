#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int n , c , idx;

ll a[1010] , e , t;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);

	cin >> c >> n >> e;

	cout << "1";

	a[0] = e;

	for(int i = 1; i < n; i++)
	{
		cin >> e;

		t = a[0];

		idx = 0;

		for(int j = 1; j < c; j++)
		{
			if(t > a[j])
			{
				t = a[j];

				idx = j;
			}
		}

		a[idx] += e;

		cout << " " << idx + 1;
	}

	cout << endl;

	return 0;

}
