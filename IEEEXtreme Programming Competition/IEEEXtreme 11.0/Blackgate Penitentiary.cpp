#include<bits/stdc++.h>
#define endl '\n'
#define maxn 300
using namespace std;

set < string > info[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextA.txt" , "r")) freopen("ArturoTextA.txt" , "r" , stdin);


    int n , r;

    string x;

    cin >> n;

    while(n--)
    {
        cin >> x >> r;

        info[r].insert(x);
    }

    int pos = 1;

    for(int i = 120; i <= 250; i++)
    {
        int how = 0;

        for(string h : info[i])
        {
            how++;
            cout << h << " ";
        }

        if(how)
        {
            cout << pos << " " << pos + how - 1 << endl;

            pos += how;
        }
    }


    return 0;
}
