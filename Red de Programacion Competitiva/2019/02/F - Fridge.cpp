#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

string x;

int a[10];

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x;

    for(int i = 0; i < x.length(); i++)
    {
        a[x[i] - '0']++;
    }

    int freq = INT_MAX;

    int n;

    for(int i = 1; i < 10; i++)
    {
        if(freq > a[i])
        {
            freq = a[i];

            n = i;
        }
    }

    cout << n;

    a[n]--;

    if(freq == 0)
    {
        cout << endl;

        return 0;
    }

    freq = INT_MAX;

    for(int i = 0; i < 10; i++)
    {
        if(freq > a[i])
        {
            freq = a[i];

            n = i;
        }
    }

    for(int i = 0; i < freq + 1; i++)
    {
        cout << n;
    }

    cout << endl;

    return 0;
}
