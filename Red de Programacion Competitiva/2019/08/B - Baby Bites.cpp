#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1010
using namespace std;

int n , c;

string num[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextB.txt" , "r")) freopen("ArturoTextB.txt" , "r" , stdin);

    cin >> n;

	c = 1;

	for (int i = 0; i < n; i++)
    {
		cin >> num[i];

		if (num[i] != "mumble" && stoi(num[i]) != c)
        {
			cout << "something is fishy" << endl;
			return 0;
		}

		c++;
	}

	cout << "makes sense" << endl;

    return 0;
}
