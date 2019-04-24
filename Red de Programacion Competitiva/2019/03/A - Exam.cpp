#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll t , dif , equ , er;

string x , y;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t >> x >> y;

    for(int i = 0; i < x.length(); i++)
    {
        dif += (x[i] != y[i]);
    }

    equ = x.length() - dif;

    er = x.length() - t;

    if(t + dif > x.length())
    {
        cout << er + equ << endl;
    }
    else
    {
        cout << t + dif << endl;
    }

    return 0;
}
