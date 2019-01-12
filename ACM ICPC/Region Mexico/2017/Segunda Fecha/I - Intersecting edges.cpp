#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while(t--)
    {
        int n , m , a , b;
        cin >> n >> m;
        set < pair < int , int > > lines;
        for(int i = 0; i < m; i++)
        {
           cin >> a >> b;
           lines.insert(make_pair(a , b));
        }
        int intersections = 0;
        set < pair < int , int > > :: iterator itfi = lines.begin();
        set < pair < int , int > > :: iterator itse;

        for(int i = 0; i < m - 1; i++ , itfi++)
        {
            itse = itfi;
            itse++;

            while(itfi->second > itse->first && itse != lines.end())
            {
                if(itfi->second < itse->second)
                {
                    intersections++;
                }

                itse++;
            }
        }

        cout << intersections << endl;
    }
    return 0;
}
