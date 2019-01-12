#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
#define ll long long
#define maxn 100010
using namespace std;
using namespace __gnu_pbds;

typedef tree< int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> statisticsTree;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);

    if(fopen("ArturoCIn.txt" , "r")) freopen("ArturoCIn.txt" , "r" , stdin);

    long long h , v;

    statisticsTree hor , ver;

    cin >> h >> v >> h >> v;

    vector < pair < int , int > > horizontals(h) , verticals(v);

    long long ans = (h + 1) * (v + 1);

    for(auto &it : horizontals)
    {
        cin >> it.first >> it.second;
    }

    for(auto &it : verticals)
    {
        cin >> it.first >> it.second;
    }

    sort(horizontals.begin() , horizontals.end());

    sort(verticals.begin() , verticals.end());

    for(auto &it : horizontals)
    {
        ans += hor.order_of_key(it.second);

        hor.insert(it.second);
    }

    for(auto &it : verticals)
    {
        ans += ver.order_of_key(it.second);

        ver.insert(it.second);
    }

    cout << ans << endl;

	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
