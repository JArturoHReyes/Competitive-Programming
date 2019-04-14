#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int a , b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> a >> b)
    {
        cout << max(a , b) << endl;
    }

    return 0;
}
