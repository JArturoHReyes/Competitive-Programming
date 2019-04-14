#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 510
using namespace std;

int j , r , indice;

ll sum[maxn] , ele , maxsum = -1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> j >> r)
    {
        for(int i = 0; i < j; i++)
        {
            sum[i] = 0;
        }

        for(int i = 0; i < j * r; i++)
        {
            cin >> ele;

            sum[i % j] += ele;
        }

        maxsum = -1;

        for(int i = 0; i < j; i++)
        {
            if(maxsum <= sum[i])
            {
                maxsum = sum[i];

                indice = i + 1;
            }
        }

        cout << indice << endl;

    }

    return 0;

}
