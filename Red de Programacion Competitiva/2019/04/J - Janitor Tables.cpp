#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

double a[4];

double maxArea(double a, double b, double c, double d)
{
    double semiperimeter = (a + b + c + d) / 2;

    return sqrt((semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c) * (semiperimeter - d));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextC.txt" , "r")) freopen("ArturoTextC.txt" , "r" , stdin);

    cin >> a[0] >> a[1] >> a[2] >> a[3];

    printf("%.15f\n" , maxArea(a[0] , a[1] , a[2] , a[3]));


    return 0;
}
