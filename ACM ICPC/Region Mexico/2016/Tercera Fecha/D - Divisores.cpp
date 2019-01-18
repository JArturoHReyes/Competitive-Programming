#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;


ll a , b , c  , d , m;

void solve()
{
	stack < long long > falt;
	
	for(ll n = 1; n * n <= c; n++)
	{
		if(c % n == 0)
		{
			if(n % a == 0 && n % b != 0 && d % n != 0)
			{
				cout << n << endl; // Aqui encontramos un multiplo c
				return;
			}
		}
		
		falt.push(c / n); // Aqui serian los divisores del multiplo c
	}
	
	while(!falt.empty())
	{
		m = falt.top();
		falt.pop();
		
		if(m % a == 0 && m % b != 0 && d % m != 0)
		{
			cout << m << endl;
			return;
		}
	}
	
	cout << -1 << endl;
	
	return;
}

int main()
{
	ios_base::sync_with_stdio(0) , cin.tie(0);
	
	while(cin >> a >> b >> c >> d)
	{
		if(b == 1)
		{
			cout << -1 << endl; // Como rayos 1 no sera divisor de algun numero n?? xd
		}
		else
		{
			solve();
		}
	}
	return 0;
}
