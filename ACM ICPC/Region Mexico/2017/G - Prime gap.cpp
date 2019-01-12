#include<bits/stdc++.h>
using namespace std;

int P[100021], Pt = 0;
//vector < int > P;

void sieve()
{

#define MAXL (1300000>>5)+1
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5] |= 1<<(x&31))

	static int mark[MAXL] = {};
    SET(1);
    int n = 1300000;

    for (int i = 2; i <= n; i++)
    {
        if (!GET(i))
        {

            for (int k = n/i, j = i*k; k >= i; k--, j -= i)
            {
                SET(j);
            }

            P[Pt++] = i;
            //P.push_back(i);
        }
    }

}

int primomaschiquito(int x)
{
    int i;

    for(i = 0; i < Pt; i++)
    {
        if(P[i] >= x)
        {
            return i;
        }
    }

    return i;
}


int main()
{
    sieve();
    int a , b;
    while(cin >> a >> b && a && b)
    {

        int c = max(a,b);
        int d = min(a,b);
        a = d;
        b = c;

        if(a == b)
        {
           cout << "NULL" << endl;
        }
        else
        {
            int posicion = primomaschiquito(a);

            if(posicion >= Pt - 1)
            {
                cout << "NULL" << endl;
            }
            else
            {
                int maxgrap = 0;


                for(int i = posicion; P[i + 1] <= b; i++)
                {
                        maxgrap = max(maxgrap , P[i + 1] - P[i]);
                }

                if(maxgrap == 0)
                {
                    cout << "NULL" << endl;
                }
                else
                {
                    cout << maxgrap << endl;
                }

            }

        }

    }
    return 0;
}
