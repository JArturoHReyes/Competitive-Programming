#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1010
using namespace std;

int X, N, M, T;

int a, b;

int mincost[maxn][maxn];

int rtime[maxn];

int rcost[maxn];

vector < int > adj[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextC.txt" , "r")) freopen("ArturoTextC.txt" , "r" , stdin);

    cin >> X >> N >> M >> T;

	for(int i = 0; i < M; i++)
    {
		cin >> a >> b;

		a--, b--;

		adj[b].push_back(a);

		adj[a].push_back(b);
	}

	for(int i = 0; i < N; i++)
    {
        cin >> rtime[i] >> rcost[i];

        mincost[0][i] = 1e9;
    }

	mincost[0][0] = 0;

	if (rtime[0] > X)
    {
		cout << "It is a trap." << endl;

		return 0;
	}

	X -= rtime[0];

	for(int t = 1; t <= X; t++)
    {
        for(int i = 0; i < N; i++)
        {
            if (rtime[i] > t)
            {
                mincost[t][i] = 1e9;
            }
            else
            {
                mincost[t][i] = mincost[t - rtime[i]][i];

                for(int to : adj[i])
                {
                    if (t >= rtime[i] + T)
                    {
                        mincost[t][i] = min(mincost[t][i], mincost[t - rtime[i] - T][to]);
                    }
                }

                mincost[t][i] += rcost[i];
            }
        }
    }

    if (mincost[X][0] < 1e9)
    {
        cout << rcost[0] + mincost[X][0] << endl;

        return 0;
    }

	cout << "It is a trap." << endl;


    return 0;
}
