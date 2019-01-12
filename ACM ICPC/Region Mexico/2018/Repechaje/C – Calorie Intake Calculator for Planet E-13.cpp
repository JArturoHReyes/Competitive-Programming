#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define maxn 10000010
using namespace std;

//ll dp[maxn];

ll a[maxn];

ll calorie;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(2) << fixed;
    
    int n , q , day , month , year , lastyear , lastmonth , lastday , pos;
    
    scanf("%d %d" , &n , &q);
    
    scanf("%d/%d/%d" , &year , &month , &day);
    
    int mini = year * 50 * 20 + month * 50 + day;
    
    //cout << "very mini = " << mini << endl;
    
    scanf("%d/%d/%d" , &year , &month , &day);
    
    int maxi = year * 50 * 20 + month * 50 + day;
    
    //cout << "very maxi = " << maxi << endl;
    
    char c;
    
    for(int i = 0; i < n; i++)
    {
        scanf(" %c %d/%d/%d %I64d", &c , &year , &month , &day , &calorie);
        
       // cout << "year = " << year << " month = " << month << " day = " << day << " calorie = " << calorie << endl;
        
        int pos = year * 50 * 20 + month * 50 + day;
        
       // cout << "pos = " << pos << endl;
        
        a[pos] += calorie;
    }
    
    for(int i = mini; i <= maxi; i++)
    {
        a[i] = a[i - 1] + a[i];
        
        //cout << "a [ " << i << " ] = " << a[i] << endl;
    }
    
    for(int i = 0; i < q; i++)
    {
        scanf(" %c%d/%d/%d%d/%d/%d", &c ,  &year , &month , &day , &lastyear , &lastmonth , &lastday);
        
        //cout << "year = " << year << " month = " << month << " day = " << day << endl;
        
        mini = year * 50 * 20 + month * 50 + day - 1;
        
        //cout << "actual mini = " << mini << endl;
        
        //cout << "a = " << a[mini] << endl;
        
        // cout << "lastyear = " << lastyear << " lastmonth = " << lastmonth << " lastday = " << lastday << endl;
        
        maxi = lastyear * 50 * 20 + lastmonth * 50 + lastday;
        
        //cout << "actual maxi = " << maxi << endl; 
        
        //cout << "a = " << a[maxi] << endl;
        
        //cout << "ans = " << (a[maxi] - a[mini])  << endl;
        
        cout << (a[maxi] - a[mini]) << endl;
    }
    
    return 0;
}
