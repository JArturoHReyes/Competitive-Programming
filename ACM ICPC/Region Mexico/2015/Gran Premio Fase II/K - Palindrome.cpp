#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 2010
using namespace std;

string x;

bool is_special[maxn];

bool visited[maxn][maxn];

int n , p;

pair < int , int > memo[maxn][maxn];

pair < int , int > dp(int i , int j)
{
    if(j < i)
    {
        return make_pair(0 , 0);
    }

    if(j == i)
    {
        return make_pair(is_special[i] , 1);
    }

    if(visited[i][j])
    {
        return memo[i][j];
    }

    visited[i][j] = true;

    pair < int , int > ans = dp(i + 1 , j - 1);

    if(x[i] == x[j])
    {
        pair < int , int > pal = dp(i + 1 , j - 1);

        pal.first += is_special[i] + is_special[j];

        pal.second += 2;

        ans = max(ans , pal);
    }

    ans = max(ans , dp(i + 1 , j));

    ans = max(ans , dp(i , j - 1));

    return memo[i][j] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> x)
    {
        cin >> n;

        memset(is_special , false , sizeof(is_special));

        memset(visited , false , sizeof(visited));

        while(n--)
        {
            cin >> p;

            is_special[p - 1] = true;
        }

        cout << dp(0 , x.length() - 1).second << endl;
    }


    return 0;
}
