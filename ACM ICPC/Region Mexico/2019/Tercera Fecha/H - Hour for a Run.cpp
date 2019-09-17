#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

double d , goal , llevo;

double n , v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextH.txt" , "r")) freopen("ArturoTextH.txt" , "r" , stdin);

	cin >> n >> v;
	
	goal = n * v;
	
	d = goal / 10.0;
	
	for(int i = 1; i <= 8; i++)
	{
		llevo += d;
		
		cout << int(ceil(llevo)) << " ";
	}
	
	llevo += d;
	
	cout << int(ceil(llevo)) << endl;

    return 0;
}
