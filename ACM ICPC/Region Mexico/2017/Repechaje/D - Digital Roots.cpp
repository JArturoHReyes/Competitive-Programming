#include<bits/stdc++.h>
using namespace std;

int main()
{
    string x;
    fflush(stdin);
    while(getline(cin , x) && x != "0")
    {
        long long int num = 10;
    long long int numc = num;
    while(num >= 10)
    {
        num = 0;
        for(int i = 0; i < x.length(); i++)
        {
            num += (x[i] - 48);
        }
        numc = num;
        x.erase();
        while(numc)
        {
            x += ((numc % 10) + 48);
            numc/=10;
        }
    }

    cout << num << endl;
    }


    return 0;
}
