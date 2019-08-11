#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n , idx , ans , cur , cnt;

int a[1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextC.txt" , "r")) freopen("ArturoTextC.txt" , "r" , stdin);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a , a + n);

	for(int d = 1; d <= 400; d++)
    {
		cur += cnt;

		if(cur >= 20)
		{
			ans++;

			cur = 0;

			cnt = 0;
		}

		if(idx < n && d == a[idx])
        {
            idx++ , cnt++;
        }
	}

	cout << ans << endl;

    return 0;
}
