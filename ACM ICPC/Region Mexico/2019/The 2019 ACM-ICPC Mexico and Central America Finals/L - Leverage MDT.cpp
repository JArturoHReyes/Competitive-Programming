#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int m , n , low , high , ans , mid , column;

string x;

string prr;

int dp[1010][1010];

bool can(int side)
{
	deque < int > d(side);

	int i = 0;

	for(; i < side; i++)
	{
		while(!d.empty() && dp[i][column] <= dp[d.back()][column])
					d.pop_back();

		d.push_back(i);
	}

	for(; i < n; i++)
	{
		if(dp[d.front()][column] >= side)
		{
			return true;
		}

		while(!d.empty() && d.front() <= i - side)
		       d.pop_front();

		while(!d.empty() && dp[i][column] <= dp[d.back()][column])
					d.pop_back();

		d.push_back(i);
	}

	if(dp[d.front()][column] >= side) return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		cin >> x;

		dp[i][0] = 1;

		for(int j = 1; j < m; j++)
		{
			if(x[j] == x[j - 1])
			{
				dp[i][j] = dp[i][j - 1] + 1;
			}
			else
			{
				dp[i][j] = 1;
			}
		}
	}

	for(column = 0; column < m; column++)
	{
		low = 1 , high = column + 1;

		while(low <= high)
		{
			mid = (low + high) >> 1;

			if(can(mid))
			{
				ans = max(ans , mid);

				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
	}

	cout << ans * ans << endl;

	return 0;
}
