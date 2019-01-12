#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);

    if(fopen("ArturoIIn.txt" , "r")) freopen("ArturoIIn.txt" , "r" , stdin);

    int numerointerruptores , numerolamparas , m;

    cin >> numerointerruptores >> numerolamparas;

    bitset < 1010 > lamparas , confinicial;

    int k , r;

    cin >> k;

    while(k--)
    {
        cin >> r;
        lamparas[r] = 1;
    }

    confinicial = lamparas;

    bitset < 1010 > interruptores[1010];

    for(int i = 0; i < numerointerruptores; i++)
    {
        cin >> m;

        while(m--)
        {
            cin >> r;
            interruptores[i][r] = 1;
        }
    }

    int ope = 0 , pasos = 0;

    while(ope++ <= 100)
    {
        for(int i = 0; i < numerointerruptores; i++)
        {
            pasos++;

            lamparas ^= interruptores[i];

            if(lamparas.count() == 0)
            {
                cout << pasos << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
