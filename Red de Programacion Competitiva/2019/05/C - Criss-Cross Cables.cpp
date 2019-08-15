#include<bits/stdc++.h>
#define endl '\n'
#define maxn 500010
using namespace std;

int n , m , idx;

int x[maxn] , l[maxn];

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);

	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
	}

	for(int i = 0; i < m; i++)
	{
		cin >> l[i];
	}

	sort(l , l + m);

	for(int i = n - 1; i > 0; i--)
	{
		x[i] -= x[i - 1];
	}

	x[0] = 0;

	priority_queue < pair < int , int > > p;

	for(int i = 1; i < n; i++)
	{
		p.emplace(-x[i] , i + 1);
	}

	while(!p.empty())
	{
		auto t = p.top();

		p.pop();

		if(t.second < n)
		{
			p.emplace(t.first - x[t.second] , t.second + 1);
		}
		
		if(l[idx] >= -t.first)
		{
			idx++;
		}
		else
		{
			break;
		}
	}

	if(idx == m)
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}


	return 0;

}
