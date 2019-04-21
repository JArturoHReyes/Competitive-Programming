#include<bits/stdc++.h>
#define endl '\n'
#define maxn 10010
using namespace std;

int lefttree[maxn][2];

int righttree[maxn][2];

int n1 , n2 , p , l , c , r;

int cntleftcenter , cntrightcenter;

int maxleftbranch , maxrightbranch;

void dfs1(int actualparent , int acum , bool supercenter)
{
    if(supercenter)
    {
        cntleftcenter++;
    }

    acum++;

    if(lefttree[actualparent][0] != 0)
    {
        dfs1(lefttree[actualparent][0] , acum , supercenter);
    }
    else
    {
        maxleftbranch = max(maxleftbranch , acum);
    }

    if(lefttree[actualparent][1] != 0)
    {
        dfs1(lefttree[actualparent][1] , acum , false);
    }
}

void dfs2(int actualparent , int acum , bool supercenter)
{
    if(supercenter)
    {
        cntrightcenter++;
    }

    acum++;

    if(righttree[actualparent][0] != 0)
    {
        dfs2(righttree[actualparent][0] , acum , supercenter);
    }
    else
    {
        maxrightbranch = max(maxrightbranch , acum);
    }

    if(righttree[actualparent][1] != 0)
    {
        dfs2(righttree[actualparent][1] , acum , false);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n1;

    for(int i = 0; i < n1; i++)
    {
        cin >> p >> l >> c;

        lefttree[p][0] = c;

        lefttree[p][1] = l;
    }

    cin >> n2;

    for(int i = 0; i < n2; i++)
    {
        cin >> p >> c >> r;

        righttree[p][0] = c;

        righttree[p][1] = r;
    }

    dfs1(1 , 0 , 1);

    dfs2(1 , 0 , 1);

    int maxintersection = max(min(cntleftcenter , maxrightbranch) , min(cntrightcenter , maxleftbranch));

    cout << n1 + n2 - maxintersection << endl;

    return 0;
}
