#include<bits/stdc++.h>
using namespace std;

int imprimir(long long int x)
{

    if(x == 0)
    {
        cout << "1";
        return 0;
    }
    int y = 0;
    long long int vec1[100];
    long long int vec2[100];
    long long int nivel = 1;
    vec1[0] = 1;
    vec1[1] = 1;
    vec2[0] = 1;
    long long int pos = 1;
    while(nivel < x)
    {
        nivel++;
        pos = 1;
        while(pos < nivel)
        {
            vec2[pos] = vec1[pos] + vec1[pos - 1];
            pos++;
        }
        vec2[pos] = 1;
        for(long long int i = 0; i <= pos; i++)
        {
            vec1[i] = vec2[i];
        }
    }

    int indice = 0;
    while(x)
    {
        if(vec2[indice] != 1)
        {
            cout << vec2[indice];
        }
        indice++;

        if(x != 0)
        {
            if(x == 1)
            {
                cout << "x";
            }
            else
            {
                cout << "x^" << x;
            }
        }
        x--;
        if(y != 0)
        {
            if(y == 1)
            {
                cout << "y";
            }
            else
            {
                cout << "y^" << y;
            }
        }
        y++;
        cout << "+";
        if(x != 0)
        {

        }
        else
        {
           if(y == 1)
            {

                cout << "y";
            }
            else
            {
                cout << "y^" << y;
            }
        }
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        imprimir(n);
        cout << endl;
    }
    return 0;
}
