#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);

    if(fopen("ArturoDIn.txt" , "r")) freopen("ArturoDIn.txt" , "r" , stdin);

    int n , a , ans = 0;

    cin >> n;

    while(n--)
    {
        cin >> a;

        if(a == 2 || a == 3)
        {
            ans++;
        }
    }

    cout << ans << endl;


	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
