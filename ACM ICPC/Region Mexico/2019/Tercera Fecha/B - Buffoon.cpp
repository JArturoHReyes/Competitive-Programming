#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n , a[10010];

int maxi = -1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextB.txt" , "r")) freopen("ArturoTextB.txt" , "r" , stdin);

	cin >> n >> a[0];
	
	for(int i = 1; i < n; i++)
	{
		cin >> a[i];
		
		maxi = max(maxi , a[i]);
	}
	
	if(a[0] >= maxi)
	{
		cout << "S" << endl;
	}
	else
	{
		cout << "N" << endl;
	}
	
    return 0;
}
