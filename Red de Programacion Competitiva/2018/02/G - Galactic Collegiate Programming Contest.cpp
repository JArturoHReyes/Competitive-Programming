#include<bits/stdc++.h>
#define endl '\n'
#define maxn 100010
using namespace std;

int n , m;

int problems[maxn];

int penalty[maxn];

int t , p , i;

set < int > better , aux;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> t >> p;

        problems[t]++;

        penalty[t] += p;

        if(t != 1)
        {
            if(problems[t] > problems[1])
            {
                better.insert(t);
            }
            else
            {
                if(problems[t] == problems[1] && penalty[t] < penalty[1])
                {
                    better.insert(t);
                }
            } 
        }
        else
        {
            aux = better;

            for(int team : better)
            {
                if(problems[team] < problems[1])
                {
                    aux.erase(team);
                }
                else
                {
                    if(problems[team] == problems[1] && penalty[team] >= penalty[1])
                    {
                        aux.erase(team);
                    }
                }
            }

            better = aux;
        }

        /*cout << "betters" << endl;

        for(int team : better)
        {
            cout << "team = " << team << endl;

            cout << "Problems = " << problems[team] << " penalty = " << penalty[team] << endl;
        }*/

        cout << better.size() + 1 << endl;
    }

    return 0;
}
