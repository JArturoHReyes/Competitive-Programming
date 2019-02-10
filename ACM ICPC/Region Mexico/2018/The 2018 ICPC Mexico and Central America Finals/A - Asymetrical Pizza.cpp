#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    //if(fopen("ArturoTextA.txt" , "r")) freopen("ArturoTextA.txt" , "r" , stdin);

    double r;
    
    cin >> r;
    
    int n = int((r * 1000 + 5) / 10);
    
    //cout << "n = " << n << endl;
    
    int ans = 0 , total = 36000;
    
    for(int i = 1; i <= 36000; i++)
    {
        if((total % i) == 0 && (n % (total / i)) == 0)
        {
            ans = i;
            break;
        }
    }
    
    cout << ans << endl;

    return 0;
}
