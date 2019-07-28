#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
int p[ MAXN ];
int n;

vector<pair<int, pair<int, int> > > edges;

void init() {
    for (int i = 0; i < MAXN; ++i) {
        p[ i ] = i;
    }
}

int find_root(int v) {
    if (p[ v ] == v) {
        return v;
    }
    return p[ v ] = find_root(p[ v ]);
}

int main(int argc, char const *argv[])
{
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        init();
        edges.clear();
        scanf("%d", &n);
        int cities = n;
        int q;
        scanf("%d", &q);
        for (int i=0; i < q; i++) {
            int a, b, v;
            scanf("%d %d %d", &a, &b, &v);
            if (a > b) {
                swap(a, b);
            }
            if (find_root(a) != find_root(b)) {
                p[ find_root(b) ] = a;
                cities--;
            }
        }

        scanf("%d", &q);
        for (int i=0; i < q; i++) {
            int a, b, v;
            scanf("%d %d %d", &a, &b, &v);
            if (a > b) {
                swap(a, b);
            }
            if (cities != 1) {
                edges.push_back(make_pair(v, make_pair(a, b)));
            }
        }
        if (cities == 1) {
            puts("Thank you, Goodbye");
            continue;
        }

        sort(edges.begin(), edges.end());
        long long ans = 0LL;
        for (auto edge : edges) {
            long long cost = edge.first;
            int a = edge.second.first;
            int b = edge.second.second;
            if (find_root(a) != find_root(b)) {
                p[ find_root(b) ] = a;
                cities--;
                ans += cost;
            }
        }
        if (cities != 1) {
            puts("You better hire someone else");
            continue;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
