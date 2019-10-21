#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1010
using namespace std;

int r , c , k , ans;

int s[maxn][maxn];

bool visited[maxn][maxn];

int dx[] = {1 , 0 , -1 , 0};

int dy[] = {0 , 1 , 0 , -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> s[i][j];
        }
    }

    int low = 0 , high = 1e9;

    while(low < high)
    {
        int mid = (low + high + 1) / 2;

        bool toprow = false;

        int used = 0;

        memset(visited , false , sizeof(visited));

        vector < pair < int , int > > ar , ab;

        for(int i = 0; i < c; i++)
        {
            visited[r - 1][i] = true;

            if(s[r - 1][i] >= mid)
            {
                ar.push_back(make_pair(r - 1 , i));
            }
            else
            {
                ab.push_back(make_pair(r - 1 , i));
            }
        }

        while(ar.size() + ab.size() > 0)
        {
            if(ar.empty())
            {
                ar = move(ab);

                ab.clear();

                if(++used > k)
                {
                    break;
                }
            }

            int actualr = ar.back().first , actualc = ar.back().second;

            ar.pop_back();

            if(actualr == 0)
            {
                toprow = true;

                break;
            }

            for(int i = 0; i < 4; i++)
            {
                int rr = actualr + dx[i];

                int cc = actualc + dy[i];

                if(min(rr , cc) >= 0 && rr < r && cc < c && !visited[rr][cc])
                {
                    visited[rr][cc] = true;

                    if(s[rr][cc] >= mid)
                    {
                        ar.push_back(make_pair(rr , cc));
                    }
                    else
                    {
                        ab.push_back(make_pair(rr , cc));
                    }
                }
            }
        }

        if(toprow)
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << low << endl;

    return 0;
}
