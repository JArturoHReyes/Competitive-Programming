#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , k;
    while(cin >> k >> n)
    {
        int frequenceplusx[k] = {0};
        int frequenceminusx[k] = {0};
        int frequencemoreless[k] = {0};
        int num;

        for(int i = 0; i < n; i++)
        {
            cin >> num;
            frequenceplusx[num - 1]++;
            frequenceminusx[num - 1]++;
            frequencemoreless[num - 1]++;
        }

        // check if +x is possible

        int indexplusx = -1;
        int minimum = 100000;

        for(int i = 0; i < k; i++)
        {
            if(minimum > min(minimum , frequenceplusx[i]))
            {
                minimum = frequenceplusx[i];
                indexplusx = i;
            }
        }

        frequenceplusx[indexplusx]++;

        int frequence = frequenceplusx[0];

        bool possibleplusx = true;

        for(int i = 1; i < k; i++)
        {
            if(frequence != frequenceplusx[i])
            {
                possibleplusx = false;
                break;
            }
        }

        // check if +x is possible

        // check if -x is possible

        int indexminusx = -1;
        int maximum = 0;

        for(int i = 0; i < k; i++)
        {
            if(maximum < max(maximum , frequenceminusx[i]))
            {
                maximum = frequenceminusx[i];
                indexminusx = i;
            }
        }

        frequenceminusx[indexminusx]--;

        frequence = frequenceminusx[0];

        bool possibleminusx = true;

        for(int i = 1; i < k; i++)
        {
            if(frequence != frequenceminusx[i])
            {
                possibleminusx = false;
                break;
            }
        }

        // check if +x is possible

        // check if -x +y is possible

        frequencemoreless[indexplusx]++;
        frequencemoreless[indexminusx]--;

        bool possiblemoreless = true;

        frequence = frequencemoreless[0];

        for(int i = 1; i < k; i++)
        {
            if(frequence != frequencemoreless[i])
            {
                possiblemoreless = false;
                break;
            }
        }

        // check if -x +y is possible

        if(possibleplusx)
        {
            cout << "+" << indexplusx + 1 << endl;
        }
        else
        {
            if(possibleminusx)
            {
                cout << "-" << indexminusx + 1 << endl;
            }
            else
            {
                if(possiblemoreless)
                {
                    cout << "-" << indexminusx + 1 << " +" << indexplusx + 1 << endl;
                }
                else
                {
                    cout << "*" << endl;
                }
            }
        }


    }
    return 0;
}
