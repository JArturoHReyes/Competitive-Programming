#include<bits/stdc++.h>
#define endl '\n'
#define maxn 210
using namespace std;

int n , m;

bool g[maxn][maxn];

map < string , int > info;

int idx_c(string a)
{
    if(!info.count(a))
    {
        info[a] = info.size();
    }

    return info[a];
}

string A , are , worst, than , B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextD.txt" , "r")) freopen("ArturoTextD.txt" , "r" , stdin);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> A >> are >> worst >> than >> B;

        g[idx_c(A)][idx_c(B)] = 1;
    }


    for(int k = 0; k < maxn; k++)
    {
        for(int i = 0; i < maxn; i++)
        {
            for(int j = 0; j < maxn; j++)
            {
                g[i][j] |= g[i][k] && g[k][j];
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        cin >> A >> are >> worst >> than >> B;

        if(g[idx_c(A)][idx_c(B)])
        {
            cout << "Fact" << endl;
        }
        else if(g[idx_c(B)][idx_c(A)])
        {
            cout << "Alternative Fact" << endl;
        }
        else
        {
            cout << "Pants on Fire" << endl;
        }
    }

    return 0;
}
