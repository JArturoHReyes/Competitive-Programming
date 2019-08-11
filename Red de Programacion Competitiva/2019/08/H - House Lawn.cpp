#include<bits/stdc++.h>
//#define endl '\n'
#define ll long long
#define maxn 110
using namespace std;

ll l , m , a[maxn] , c , t , r;

char lawnmower[maxn][70];

char ch;

int cnt , pos;

const ll week = 10080LL;

const ll inf = 1e18;

ll ans;

void re(int idx)
{
    scanf("%c" , &ch);

    pos = 0;

    while(ch != ',')
    {
        lawnmower[idx][pos++] = ch;

        scanf("%c" , &ch);
    }

    lawnmower[idx][pos] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(3) << fixed;

    if(fopen("ArturoTextH.txt" , "r")) freopen("ArturoTextH.txt" , "r" , stdin);

    scanf("%lld %lld\n", &l , &m);

    ans = inf;

    for(int i = 0; i < m; i++)
    {
        re(i);

        scanf("%lld,%lld,%lld,%lld\n" , &a[i] , &c , &t , &r);

        if(week * c * t < l * (t + r))
        {
            a[i] = inf;
        }

        if(a[i] < ans)
        {
            ans = a[i];
        }
    }

    if(ans != inf)
    {
        for(int i = 0; i < m; i++)
        {
            if(a[i] == ans)
            {
                puts(lawnmower[i]);
            }
        }
    }
    else
    {
        puts("no such mower");
    }

    return 0;
}
