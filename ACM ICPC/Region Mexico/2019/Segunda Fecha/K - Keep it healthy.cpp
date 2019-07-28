#include<bits/stdc++.h>
#define endl '\n'
#define maxn 310
using namespace std;

int r , c;

int m[maxn][maxn];

int ans[maxn][maxn] , ans2[maxn][maxn];

int k;

void p()
{
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cout << ans2[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextK.txt" , "r")) freopen("ArturoTextK.txt" , "r" , stdin);

    cin >> r >> c;

    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cin >> m[i][j];
        }
    }

    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(m[i][j] != 0)
            {
                ans[i][j] = 0;
            }
            else
            {
                ans[i][j] = ans[i][j - 1] + 1;
            }
        }
    }

    int actual = 0;

    int altura = 0 ,  lado = 1e9;

    for(int i = 1; i <= c; i++)
    {
        altura = 0;

        lado = 1e9;

        for(int j = 1; j <= r; j++)
        {
            if(ans[j][i] == 0)
            {
                altura = 0;

                lado = 1e9;
            }
            else
            {
                altura++;

                lado = min(lado , ans[j][i]);

                k = max(k , (altura + lado) * 2);
            }

            /*cout << "j = " << i << endl;

            cout << "j = " <<*/
        }
    }

    for(int i = 1; i <= c; i++)
    {
        for(int j = r; j >= 1; j--)
        {
            if(m[j][i] != 0)
            {
                ans2[j][i] = 0;
            }
            else
            {
                ans2[j][i] = ans2[j + 1][i] + 1;
            }
        }
    }

    //p();

    for(int i = r; i >= 1; i--)
    {
        altura = 0;

        lado = 1e9;

        for(int j = 1; j <= c; j++)
        {
            if(ans2[i][j] == 0)
            {
                altura = 0;

                lado = 1e9;
            }
            else
            {
                altura++;

                lado = min(lado , ans2[i][j]);

                k = max(k , (altura + lado) * 2);
            }

            /*cout << "j = " << i << endl;

            cout << "j = " <<*/
        }
    }

    //p();

    //p();

    cout << k << endl;

    return 0;
}
