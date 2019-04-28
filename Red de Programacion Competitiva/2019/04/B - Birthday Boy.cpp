#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;

int dp[15];

bool visited[365];

string d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextG.txt" , "r")) freopen("ArturoTextG.txt" , "r" , stdin);

    cin >> n;

    vector < int > days = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};

    for(int i = 1; i < 13; i++)
    {
        dp[i] = days[i - 1] + dp[i - 1];
    }

    int check = dp[9] + 27;

    int firstday = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> d >> d;

        int month = stoi(d.substr(0 , 2));

        int day = stoi(d.substr(3 , 2));

        int conv = dp[month - 1] + day - 1;

        visited[conv] = true;

        if(firstday < conv && conv <= check)
        {
            firstday = conv;
        }
    }

    int currentgap = 0 , bestgap = 0 , bestday = 0;

    for(int i = firstday; i < firstday + 2 * 365; i++)
    {
        if(!visited[i % 365])
        {
            currentgap++;

            if(currentgap > bestgap)
            {
                bestgap = currentgap;

                bestday = i % 365;
            }
        }
        else
        {
            currentgap = 0;
        }
    }

    int month = 0;

    for(; month < 13; month++)
    {
        if(bestday < dp[month])
        {
            break;
        }
    }

    month--;

    bestday -= dp[month];

    cout << setfill('0') << setw(2) << month + 1 << "-" << setw(2) << bestday + 1 << endl;

    return 0;
}
