#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int n;

string x;

ll go()
{
    array < ll , 3 > c;

    for(int i = 0; i < 3; i++)
    {
        c[i] = count(x.begin() , x.end() , 'A' + i);
    }

    ll totalgood = c[0] * c[0] + c[1] * c[1] + c[2] * c[2];

    partial_sum(c.begin() , c.end() , c.begin());

    vector < ll > v(n);

    for(int i = 0; i < n; i++)
    {
        v[(i + n - c[(x[i] - 'A') % 3]) % n]++;

        v[(i + n - c[(x[i] - 'A' + 2) % 3]) % n]--;
    }

    partial_sum(v.begin() , v.end() , v.begin());

    return *max_element(v.begin()  , v.end()) + (totalgood - accumulate(v.begin() , v.end() , 0l)) / n;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextI.txt" , "r")) freopen("ArturoTextI.txt" , "r" , stdin);

    cin >> n >> x;

    int ans1 = go();

    reverse(x.begin() , x.end());

    int ans2 = go();

    cout << n - max(ans1 , ans2) << endl;

    return 0;
}
