#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector < string > square;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextH.txt" , "r")) freopen("ArturoTextH.txt" , "r" , stdin);

    int n;

    cin >> n;

    string in;

    for(int i = 0; i < n; i++)
    {
        cin >> in;

        map < char , int > freq;

        square.push_back(in);

        for(int j = 0; j < in.length(); j++)
        {
            int y = freq[in[j]]++;

            if(y == 1)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    bool readnumbers = true;

    int last = 0;

    char actual = 'A';

    for(int i = 0; i < n; i++)
    {
        if(readnumbers)
        {
            if(square[0][i] == (last + '0'))
            {
                last++;
            }
            else
            {
                cout << "Not Reduced" << endl;
                return 0;
            }

            if(last == 10)
            {
                readnumbers = false;
            }
        }
        else
        {
            if(square[0][i] == actual)
            {
                actual++;
                //cout << "actual = " << actual << endl;
            }
            else
            {
                cout << "Not Reduced" << endl;
                return 0;
            }
        }
    }

    readnumbers = true;

    last = 0;

    actual = 'A';

    for(int i = 0; i < n; i++)
    {
        if(readnumbers)
        {
            if(square[i][0] == (last + '0'))
            {
                last++;
            }
            else
            {
                cout << "Not Reduced" << endl;
                return 0;
            }

            if(last == 10)
            {
                readnumbers = false;
            }
        }
        else
        {
            if(square[i][0] == actual)
            {
                actual++;
            }
            else
            {
                cout << "Not Reduced" << endl;
                return 0;
            }
        }
    }

    cout << "Reduced" << endl;

    return 0;
}
