#include<bits/stdc++.h>
#define endl '\n'
#define ll long double
using namespace std;

ll goatx , goaty , bx , by , ux , uy;

pair < ll , ll > borders[4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(3) << fixed;

    cin >> goatx >> goaty >> bx >> by >> ux >> uy;

    ll dist = 1e12;

    if(bx <= goatx && goatx <= ux)
    {
        dist = min(dist , abs(goaty - by));

        dist = min(dist , abs(goaty - uy));
    }

    if(by <= goaty && goaty <= uy)
    {
        dist = min(dist , abs(goatx - bx));

        dist = min(dist , abs(goatx - ux));
    }

    borders[0] = {bx , by};

    borders[1] = {bx , uy};

    borders[2] = {ux , by};

    borders[3] = {ux , uy};

    for(int i = 0; i < 4; i++)
    {
        ll distx = abs(borders[i].first - goatx);

        ll disty = abs(borders[i].second - goaty);

        ll totaldist = sqrt(distx*distx + disty*disty);

        dist = min(dist , totaldist);
    }

    cout << dist << endl;

    return 0;
}
