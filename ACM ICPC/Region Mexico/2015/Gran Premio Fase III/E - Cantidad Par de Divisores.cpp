#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll n , m;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*for(int i = 1; i <= 100; i++)
    {
        set < int > x;

        for(int j = 1; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                x.insert(j);

                x.insert(i / j);
            }
        }

        int y = x.size();

        cout << i << "->" << int(y & 1) << endl;
    }*/

    while(cin >> n >> m && n)
    {
        ll k = m - n + 1;

        ll sn = sqrt(n);

        if(sn * sn < n)
        {
            sn++;
        }

        ll sm = sqrt(m);

        ll h = sm - sn + 1;

        /*cout << "square n = " << sn << endl;

        cout << "square m = " << sm << endl;

        cout << " h = " << h << endl;

        cout << "ans = " << k - h << endl;*/

        cout << k - h << endl;
    }

    return 0;
}
