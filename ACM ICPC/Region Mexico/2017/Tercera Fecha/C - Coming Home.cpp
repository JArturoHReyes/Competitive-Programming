#include<bits/stdc++.h>
using namespace std;

int main()
{
    int bits , n;

    while(cin >> bits >> n)
    {
        cout << "Instructions: ";
        int mayor = pow(2 , bits) - 1;
        if(mayor != n)
        {
            int rangop = 2;
            int expar = 2;
            int piso = 0;
            int npiso = 0;
            while(true)
            {
                if((mayor - rangop <= n) && (mayor - (rangop / 2) >= n))
                {
                    npiso = mayor - rangop;
                    expar *= 2;
                    rangop += expar;
                    piso++;
                    break;
                }
                else
                {
                    npiso = mayor - rangop;
                    expar *= 2;
                    rangop += expar;
                    piso++;
                }

            }

            int difference = n - npiso;
            int binary[piso];
            int pos = 0;

            while(difference)
            {
                if(difference % 2 == 1)
                {
                    binary[pos++] = 1;
                }
                else
                {
                    binary[pos++] = 0;
                }
			  difference = difference / 2;
            }

            while(pos != piso)
            {
                binary[pos++] = 0;
            }

            for(int l = pos - 1; l >= 0; l--)
            {
                if(binary[l] == 0)
                {
                    cout << "R";
                }
                else
                {
                    cout << "L";
                }
            }
        }

    cout << endl;

    }

    return 0;
}
