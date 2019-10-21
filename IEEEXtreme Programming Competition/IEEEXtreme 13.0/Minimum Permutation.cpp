#include<bits/stdc++.h>
#define endl '\n'
#define maxn 200010
using namespace std;

string filename = "b.txt";

int n , m , e;

int a[maxn];

set < int > b;

vector < int > answers;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if(fopen(filename.c_str() , "r")) freopen(filename.c_str() , "r" , stdin);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++)
    {
        cin >> e;

        b.insert(e);
    }

    for(int i = 0; i < n; i++)
    {
        while(b.size() > 0)
        {
            auto it = b.begin();

            if(*it > a[i])
            {
                break;
            }

            answers.push_back(*it);

            b.erase(*it);
        }

        answers.push_back(a[i]);
    }

    while(b.size() > 0)
    {
        auto it = b.begin();

        answers.push_back(*it);

        b.erase(*it);
    }

    for(int i = 0; i < answers.size() - 1; i++)
    {
        cout << answers[i] << " ";
    }

    cout << answers[answers.size() - 1] << endl;

    return 0;
}
