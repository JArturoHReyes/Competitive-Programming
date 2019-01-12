#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) , cout.precision(10);
#define in if(fopen("in.txt" , "r")) freopen("in.txt" , "r" , stdin);
#define out freopen("output.txt" , "w" , stdout);
#define endl '\n'
#define tle cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#define ll long long
using namespace std;

int main()
{
    opt; in;

    bool ok1 = true , ok2 = true;

    int k , p , b;

    cin >> k;

    while(k--)
    {
        cin >> p >> b;

        if(p == 1)
        {
            ok1 = false , ok2 = false;
            break;
        }

        if(ok1)
        {
            if(p >= 3 && ((p - 3) % 4) == 0 && (b % 2) != 0)
            {
               ok1 = false;
            }
        }

        if(ok2)
        {
            if(p == 2 || ((p - 1) % 4) == 0)
            {
                ok2 = true;
            }
            else
            {
                ok2 = false;
            }
        }
    }

    if(ok1 || ok2)
    {
        cout << "Yes." << endl;
    }
    else
    {
        cout << "No." << endl;
    }

    return 0;

}
