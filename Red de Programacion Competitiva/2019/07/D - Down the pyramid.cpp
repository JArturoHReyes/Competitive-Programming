#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int n;

ll low , high , sum , x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextD.txt" , "r")) freopen("ArturoTextD.txt" , "r" , stdin);

    cin >> n;

    high = 1e9;

	for (int i = 0; i < n; i++)
    {
		cin >> x;

		sum = x - sum;

		if (i & 1)
        {
            low = max(low , -sum);
        }
		else
        {
            high = min(high , sum);
        }

        //cout << "i = " << i << " sum = " << sum << " low = " << low << " high = " << high << endl;
	}

	cout << max(0LL , high - low + 1LL) << endl;

    return 0;
}
