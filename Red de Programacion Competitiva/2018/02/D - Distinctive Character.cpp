#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n , k , actual , ans;

string x;

int dist[1 << 20];

queue < int > q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < (1 << k); i++)
    {
        dist[i] = 1e9;
    }

    for(int i = 0; i < n; i++)
    {
        cin >> x;

        actual = 0;

        for(int j = 0; j < k; j++)
        {
            actual += (1 << j) * (x[j] - '0');
        }

        dist[actual] = 0;

        q.push(actual);
    }

    while(!q.empty())
    {
        actual = q.front();

        q.pop();

        ans = actual;

        for(int i = 0; i < k; i++)
        {
            int to = actual ^ (1 << i);

            if(dist[actual] + 1 < dist[to])
            {
                dist[to] = dist[actual] + 1;

                q.push(to);
            }
        }
    }

    for(int i = 0; i < k; i++)
    {
        cout << bool((ans & (1 << i)) > 0);
    }

    cout << endl;

    return 0;
}
