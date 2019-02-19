#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextM.txt" , "r")) freopen("ArturoTextM.txt" , "r" , stdin);

    int n;

    cin >> n;

    while(true)
    {
        n++;

        int y = n;

        bool ok = true;

        while(y)
        {
            int r = y % 10;

            if(r == 0)
            {
                ok = false;
                break;
            }

            y /= 10;
        }

        if(ok)
        {
            cout << n << endl;
            return 0;
        }
    }

    return 0;
}
