#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1010
using namespace std;

int n;

int a[maxn] , b[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextI.txt" , "r")) freopen("ArturoTextI.txt" , "r" , stdin);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    if(a[0] > b[0])
    {
        cout << 0 << endl;

        return 0;
    }

    int i = 0;

    while(i < n && a[i] + (b[0] - a[0]) == b[i])
    {
        i++;
    }

    if(i == n)
    {
        cout << b[0] - a[0] << endl;

        return 0;
    }

    if(a[i] + (b[0] - a[0]) > b[i])
    {
        cout << b[0] - a[0] << endl;

        return 0;
    }

    cout << b[0] - a[0] + 1 << endl;

    return 0;
}
