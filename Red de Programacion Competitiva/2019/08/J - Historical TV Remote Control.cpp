#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int n , m;

int a;

bool notpossible[100];

string c;

int mini , ans;

bool ispossible(string t)
{
    /*if(t == 0)
    {
        return notpossible[t];
    }

    while(t)
    {
        if(notpossible[t % 10])
        {
            return false;
        }

        t /= 10;
    }

    return true;*/

    for(char j : t)
    {
        if(notpossible[j - '0'])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextJ.txt" , "r")) freopen("ArturoTextJ.txt" , "r" , stdin);

    cin >> n;

    mini = 1e9;

    for(int i = 0; i < n; i++)
    {
        cin >> a;

        notpossible[a] = true;
    }

    cin >> ans;

    for(int i = 0; i <= 999; i++)
    {
        if(ispossible(to_string(i)))
        {
            mini = min(mini , abs(ans - i));
        }
    }

    cout << mini << endl;

    return 0;
}
