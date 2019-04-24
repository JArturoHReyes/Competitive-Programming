#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1010
using namespace std;

int a[maxn] , b[maxn];

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    for(int i = n; i >= 0; i--)
    {
        int cnt = 0;

        for(int j = 0; j < n; j++)
        {
            if(a[j] <= i && i <= b[j])
            {
                cnt++;
            }
        }

        if(cnt == i)
        {
            cout << cnt << endl;

            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
