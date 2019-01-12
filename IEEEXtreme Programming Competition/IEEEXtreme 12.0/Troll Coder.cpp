#include<bits/stdc++.h>
#define endl '\n'
#define maxn 110
using namespace std;

int answers[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextA.txt" , "r")) freopen("ArturoTextA.txt" , "r" , stdin);

    int n;

    int maxi = 0 , mini = 10000 , zeros;

    cin >> n;

    cout << "Q";

    for(int i = 0; i < n; i++)
    {
        cout << " 0";
    }

    cout << endl;

    cout.flush();

    cin >> zeros;

    if(zeros == n)
    {
        cout << "A";

        for(int i = 0; i < n; i++)
        {
            cout << " 0";
        }

        cout << endl;

        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        cout << "Q";

        for(int j = 0; j < n; j++)
        {
            if(j == i)
            {
                cout << " 1";
            }
            else
            {
                cout << " 0";
            }
        }

        cout << endl;

        cout.flush();

        cin >> answers[i];

        maxi = max(maxi , answers[i]);

        mini = min(mini , answers[i]);
    }

    cout << "A";

    if(n == 1)
    {
        if(answers[0] == 0)
        {
            cout << " 0";
        }
        else
        {
            cout << " 1";
        }

        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(answers[i] == maxi)
        {
            cout << " 1";
        }
        else
        {
            cout << " 0";
        }
    }

    cout << endl;





    return 0;
}
