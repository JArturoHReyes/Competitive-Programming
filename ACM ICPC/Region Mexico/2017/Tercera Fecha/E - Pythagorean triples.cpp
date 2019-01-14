#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin >> n && n)
    {
        int cont = 0;

        for(int i = 1; i <= 512; i++)
        {
            for(int j = 1; j <= 512; j++)
            {
                double raiz = sqrt((i*i) +(j*j));
                int raizi = (int) raiz;
                if(raiz == raizi)
                    {
                        if(raizi <= n)
                        cont++;
                    }
        }
    }
    cout << cont / 2 << endl;
    }

	return 0;
}
