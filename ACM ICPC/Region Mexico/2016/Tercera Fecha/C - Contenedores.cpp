#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 40500
using namespace std;

int id;

map < int , int > sorted , inv;

map < int , ll > dist;

int base;

int getnumber(vector < int > x)
{
    int ret = 0;

    for(int i = 0; i < x.size(); i++)
    {
        ret *= base;

        ret += sorted[x[i]];
    }

    return ret;
}

vector < int > getboard(int uniqueid)
{
    vector < int > ret(8);

    for(int i = 0; i < 8; i++)
    {
        ret[i] = inv[uniqueid % base];

        uniqueid /= base;
    }

    reverse(ret.begin() , ret.end());

    return ret;
}

struct st
{
    int node;

    ll cost;

    st(int a , ll b) : node(a) , cost(b) {}

    bool operator < (const st &o) const
    {
        return cost > o.cost;
    }
};

int t[8][3] = {
{0 , 1 , 4},
{-1 , 1 , 4},
{-1 , 1 , 4},
{-1 , 0 , 4},
{0 , 1 , -4},
{-1 , 1 , -4},
{-1 , 1 , -4},
{-1 , 0 , -4}
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    base = 10;

    vector < int > board , target;

    set < int > targets;

    board.resize(8);

    target.resize(8);

    for(int i = 0; i < maxn; i++)
    {
        dist[i] = LLONG_MAX;
    }

    for(int i = 0; i < 8; i++)
    {
        cin >> board[i];
    }

    for(int i = 0; i < 8; i++)
    {
        cin >> target[i];

        targets.insert(target[i]);
    }


    for(int it : targets)
    {
        sorted[it] = id;

        inv[id++] = it;
    }

    priority_queue < st > q;

    int uniquetarget = getnumber(target);

    int uniquestart = getnumber(board);

    dist[uniquestart] = 0;

    q.push(st(uniquestart , 0));

    while(!q.empty())
    {
        int state = q.top().node;

        q.pop();

        if(state == uniquetarget)
        {
            break;
        }

        vector < int > currentboard = getboard(state);

        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                vector < int > nx = currentboard;

                int xx = i + t[i][j];

                swap(nx[i] , nx[xx]);

                int to = getnumber(nx);

                int extra = nx[i] + nx[xx];

                if((dist.count(to) == 0) || (dist[state] + extra < dist[to]))
                {
                    dist[to] = dist[state] + extra;

                    q.push(st(to , dist[to]));
                }
            }
        }
    }

    cout << dist[uniquetarget] << endl;

    return 0;
}
