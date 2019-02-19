#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextD.txt" , "r")) freopen("ArturoTextD.txt" , "r" , stdin);

    long long r , p;

    while(cin >> r >> p)
    {



    long long y1 = (r + 1) * p - abs((r + 1) - p);

    long long y2 = r * (p + 1) - abs(r - (p + 1));

    if(y1 > y2)
    {
        cout << "Technical" << endl;
    }
    else
    {
        if(y1 == y2)
        {
            cout << "Either" << endl;
        }
        else
        {
            cout << "Interpersonal" << endl;
        }
    }
    }

    return 0;
}
