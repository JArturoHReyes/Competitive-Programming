#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll z = 1e9 + 7;

ll p = 1e5 + 1 , hashleft , hashright , pa = 1;

int ans;

bool isPrime(ll a)
{
	for(ll i = 2; i * i <= a; i++)
	{
		if(a % i == 0)
		{
			return false;
		}
	}

	return true;
}

string x;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);

	while(!isPrime(p))
	{
		p += 2;
	}

	cin >> x;

	int i = 0 , j = x.length() - 1;

	for(; i < j; i++ , j--)
	{
		hashleft = (p * hashleft + x[i]) % z;

		hashright = (hashright + x[j] * pa) % z;

		pa = (pa * p) % z;

		if(hashleft == hashright)
		{
			ans += 2;

			hashleft = hashright = 0ll;

			pa = 1;
		}
	}

	if(i == j or hashleft != hashright)
	{
		ans++;
	}

	cout << ans << endl;

	return 0;

}
