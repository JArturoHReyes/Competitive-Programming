#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 1000010
using namespace std;

int n;

ll x[maxn] , y[maxn];

ll a , b;

// pick theorem

// i - number of inside points in a polygon

// b - number of border points in a polygon

// it's area will be i + (b / 2) - 1


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextG.txt" , "r")) freopen("ArturoTextG.txt" , "r" , stdin);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    for(int i = 1; i <= n; i++)
    {
        a += x[i % n] * y[i - 1] - x[i - 1] * y[i % n]; // area of polygon

        b += __gcd(abs(x[i % n] - x[i - 1]) , abs(y[i % n] - y[i - 1])); // border points
    }

    // area = i + (b / 2) - 1 -> area + 1 - (b / 2) = i

    cout << (abs(a) - b + 2) / 2 << endl;

    return 0;
}
