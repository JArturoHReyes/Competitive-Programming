#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 10010
using namespace std;

int n;

double e , s;

ll v , actual;

ll ans[maxn];

vector < pair < pair < double , double > , ll > > info;
// last, first, value

int bs(int st)
{
	int low = 0;

	int high = st - 1;

	while(low <= high)
	{
		int mid = (low + high) >> 1;

		if(info[mid].first.first <= info[st].first.second)
		{
			if(info[mid + 1].first.first <= info[st].first.second)
			{
				low = mid + 1;
			}
			else
			{
				return mid;
			}
		}
		else
		{
			high = mid - 1;
		}
	}


	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << setprecision(5) << fixed;

	if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> s >> e >> v;

		e += 0.1;

		info.push_back(make_pair(make_pair(e , s) , v));
	}

	sort(info.begin() , info.end());

	ans[0] = info[0].second;

	for(int i = 1; i < n; i++)
	{
		actual = info[i].second;

		int idx = bs(i);

		if(idx != -1)
		{
			actual += ans[idx];
		}

		ans[i] = max(ans[i - 1] , actual);

		//cout << "idx = " << i << " ans = " << ans[i] << endl;
	}

	cout << ans[n - 1] << endl;

	return 0;
}
