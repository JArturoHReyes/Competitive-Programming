#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

map < string , int > info;

int freq[10];

int n , k , maxi , ans , sum;

string x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    info["red"] = 1;

    info["yellow"] = 2;

    info["green"] = 3;

    info["brown"] = 4;

    info["blue"] = 5;

    info["pink"] = 6;

    info["black"] = 7;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x;

        k = info[x];

        sum += k;

        maxi = max(maxi , k);

        freq[k]++;
    }

    if(freq[1] == n)
    {
        cout << 1 << endl;

        return 0;
    }

    ans += freq[1] * (maxi + 1); // 7 1 7 1 7 1

    ans += sum - freq[1]; // 7 6

    cout << ans << endl;

    return 0;
}
