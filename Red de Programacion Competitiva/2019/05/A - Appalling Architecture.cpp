#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

string x;

int n , m , sum , cnt , i , l , r;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);

	cin >> n >> r;

	while(n--)
	{
		cin >> x;

		i = 0;

		for(char c : x)
		{
			if(c != '.')
			{
				sum += i;

				cnt++;
			}

			i++;
		}
	}

	while(x[l] == '.')
	{
		l++;
	}

	while(x[r - 1] == '.')
	{
		r--;
	}

	//cout << "sum = " << sum << " l = " << l << " r = " << r << " cnt = " << cnt << endl;
 
	if(2 * sum < (2 * l - 1) * cnt)
	{
		cout << "left" << endl;
	}
	else
	{
		if(2 * sum > (2 * r - 1) * cnt)
		{
			cout << "right" << endl;
		}
		else
		{
			cout << "balanced" << endl;
		}
	}

	return 0;

}
