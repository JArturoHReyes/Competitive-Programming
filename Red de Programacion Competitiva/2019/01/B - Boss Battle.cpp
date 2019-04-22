#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);

    if(fopen("ArturoCIn.txt" , "r")) freopen("ArturoCIn.txt" , "r" , stdin);

    int n;

    cin >> n;

    if(n <= 3)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << n - 2 << endl;
    }



	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
