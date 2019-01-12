#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int letters1[26] , letters2[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);

    if(fopen("ArturoEIn.txt" , "r")) freopen("ArturoEIn.txt" , "r" , stdin);

    string x , y;

    cin >> x >> y;

    int n = x.length() , m = y.length() , ans = 0;

    //cout << n - m << endl;

    for(int i = 0; i < n - m + 1; i++)
    {
        bool ok = true;

        for(int j = 0; j < m; j++)
        {
            if(x[i + j] == y[j])
            {
                ok = false;
                //break;
            }

            //cout << x[j];
        }

        //cout << endl;

        if(ok)
        {
            ans++;
        }
    }

    cout << ans << endl;


	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
