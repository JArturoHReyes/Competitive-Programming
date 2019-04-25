#include<bits/stdc++.h>
#define endl '\n'
#define maxn 10000010
using namespace std;

vector < int > triangular;

int ans[maxn];

int n;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1; i <= maxn; i++)
    {
        ans[i] = 3;
    }

    int t = 1 , sum = 2;

    while(t <= maxn)
    {
        triangular.push_back(t);

        ans[t] = 1;

        t += sum++;
    }

    for(int i = 0; i < triangular.size(); i++)
    {
        for(int j = 0; j < triangular.size(); j++)
        {
            int aux = triangular[i] + triangular[j];

            if(aux > maxn)
            {
                break;
            }

            if(ans[aux] != 1)
            {
                ans[aux] = 2;
            }
        }
    }

    while(cin >> n)
    {
        cout << ans[n] << endl;
    }

    return 0;
}
