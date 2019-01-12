#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
#define ll long long
using namespace std;

vector < int > lista[8];

ll dp[maxn][8];

int n , m[4][maxn];

ll f(int column , int patron)
{
    if(column > n)
    {
        return 0;
    }
    
    ll &c = dp[column][patron];
    
    if(c != -1)
    {
        return c;
    }
    
    c = 0;
    
    for(auto nextpatron : lista[patron])
    {
        c = max(c , f(column + 1 , nextpatron));
    }
    
    if(patron == 1)
    {
        c += m[0][column];
    }
    
    if(patron == 2)
    {
        c += m[1][column];
    }
    
    if(patron == 3)
    {
        c += m[2][column];
    }
    
    if(patron == 4)
    {
        c += m[3][column];
    }
    
    if(patron == 5)
    {
        c += (m[0][column] + m[2][column]);
    }
    
    if(patron == 6)
    {
        c += (m[0][column] + m[3][column]);
    }
    
    if(patron == 7)
    {
        c += (m[1][column] + m[3][column]);
    }
    
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    memset(dp , -1 , sizeof(dp));
    
    lista[0].assign({1, 2, 3, 4, 5, 6, 7});
    lista[1].assign({0, 2, 3, 4, 7});
    lista[2].assign({0, 1, 3, 4, 5, 6});
    lista[3].assign({0, 1, 2, 4, 6, 7});
    lista[4].assign({0, 1, 2, 3, 5});
    lista[5].assign({0, 2, 4, 7});
    lista[6].assign({0, 2, 3});
    lista[7].assign({0, 1, 3, 5});
    
    cin >> n;
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> m[i][j];
        }
    }
    
    ll ans = f(0 , 0);
    
    cout << ans << endl;
    
    return 0;
}
