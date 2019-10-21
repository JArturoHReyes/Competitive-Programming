#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

string filename = "i.txt";

string x , y;

int n;

bool notask[1010];

vector < int > adj[1010];

set < int > k;

int uu;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //if(fopen(filename.c_str() , "r")) freopen(filename.c_str() , "r" , stdin);

    cin >> n;

    for(int i = 1; i < 2 * n; i += 2)
    {
        cout << i << " " << i + 1 << endl;

        cout.flush();

        cin >> x;

        if(x == "MATCH")
        {
            notask[i] = true;

            uu++;
        }
        else
        {
            int pos = 0;

            int firstnumber = 0 , secondnumber = 0;

            cin >> y;

            while(pos < x.length())
            {
                firstnumber *= 10;

                firstnumber += (x[pos] - '0');

                pos++;
            }

            pos = 0;

            while(pos < y.length())
            {
                secondnumber *= 10;

                secondnumber += (y[pos] - '0');

                pos++;
            }

            adj[firstnumber].push_back(i);

            adj[secondnumber].push_back(i + 1);

            k.insert(firstnumber);

            k.insert(secondnumber);
        }
    }

    for(int h : k)
    {
        cout << adj[h][0] << " " << adj[h][1] << endl;

        cout.flush();

        cin >> x;

        if(x == "MATCH")
        {
            uu++;
        }
    }

    cout << -1 << endl;

    cout.flush();

    return 0;
}
