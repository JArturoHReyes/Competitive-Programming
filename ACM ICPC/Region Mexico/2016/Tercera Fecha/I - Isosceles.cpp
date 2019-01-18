#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{	
	ios_base::sync_with_stdio(0),  cin.tie(0);
	
	int n;
	
	cin >> n;
	
	int columns[n];
	
	for(int i = 0; i < n; i++)
	{
		cin >> columns[i];
	}
	
	vector < int > leftside(n , 1);
	vector < int > rightside(n , 1);
	
	for(int i = 1; i < n; i++)
	{
		leftside[i] = min(columns[i] , leftside[i - 1] + 1);
	}
	
	for(int i = n - 2; i >= 0; i--)
	{
		rightside[i] = min(columns[i] , rightside[i + 1] + 1);
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; i++)
	{
		ans = max(ans , min(leftside[i] , rightside[i]));
	}
	
	cout << ans << endl;
	
	return 0;
}
