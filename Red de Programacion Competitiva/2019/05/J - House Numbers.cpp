#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll m , x , sum_m , sum_x , diff , sum_n , pn , k , tryn , sumtry , nowdiff;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);

	cin >> m;

	x = m;

	sum_m = m * (m - 1) / 2;

	while(true)
	{
		x++;

		sum_x = x * (x - 1) / 2;

		diff = sum_x - sum_m;

		//cout << "diff = " << diff << endl;

		sum_n = sum_x + diff;

		pn = sum_n * 2;

		pn = sqrt(pn);

		for(k = -1; k <= 1; k++)
		{
			tryn = pn + k;

			sumtry = tryn * (tryn + 1) / 2;

			nowdiff = sumtry - sum_x - x;

			//cout << "m = " << m << " x = " << x << " n = " << tryn << endl;

			//cout << "diff = " << diff << " nowdiff = " << nowdiff << endl;

			if(nowdiff == diff && (m < x && x < tryn))
			{
				cout << m << " " << x << " " << tryn << endl;

				return 0;
			}	
		}
	}

	return 0;

}
