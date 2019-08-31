#include<bits/stdc++.h>
#define endl '\n'
#define maxn 10010
#define ll long long
using namespace std;

ll n , m , s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(3) << fixed;

	if(fopen("in.txt", "r")) freopen("in.txt", "r", stdin);

    cin >> n >> m >> s;
    
    cout << (ll) (s * ceil(log2(n)) + (n - 1) * m);
    
	
 	return 0;
}
