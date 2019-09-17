#include<bits/stdc++.h>
#define endl '\n'
#define ll unsigned long long
using namespace std;

ll n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextL.txt" , "r")) freopen("ArturoTextL.txt" , "r" , stdin);

    cin >> n;

    cout << (1LL << __builtin_popcountll(n)) << endl;

    return 0;
}
