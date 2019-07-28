#include<bits/stdc++.h>
#define endl '\n'
#define maxn 1000010
#define ll long long
using namespace std;

int n;

ll a[maxn];

map < ll , int > freq;

ll ans , sum , totalelements;

int freqM1 , freqM0 , freqn1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextA.txt" , "r")) freopen("ArturoTextA.txt" , "r" , stdin);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];

        sum += a[i];

        freq[a[i]]++;
    }

    for(int i = 0; i < n - 1; i++)
    {
        freq[a[i]]--;

        sum -= a[i];

        totalelements = n - (i + 1);

        //cout << "totalelements = " << totalelements << endl;

        freqM1 = freq[a[i] + 1];

        freqM0 = freq[a[i]];

        freqn1 = freq[a[i] - 1];

        /*cout << "freq mayor1 = " << freqM1 << endl;

        cout << "freq 0 = " << freqM0 << endl;

        cout << "freq -1 = " << freqn1 << endl;*/

        totalelements -= freqM1;

        totalelements -= freqM0;

        totalelements -= freqn1;

        //cout << "totalelements = " << totalelements << endl;

        ll quitar = (freqM1 * (a[i] + 1));

        quitar += (freqM0 * a[i]);

        quitar += (freqn1 * (a[i] - 1));

        //cout << "quitar = " << quitar << endl;

        ans += (sum - quitar - totalelements * a[i]);
    }

    cout << ans << endl;

    return 0;
}
