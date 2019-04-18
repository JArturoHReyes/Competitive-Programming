#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

struct Frac {
    long long x, y;
    Frac(long long a = 0, long long b = 1) {
        x = a, y = b;
        normal();
    }
    void normal() {
        if (y < 0)  x = -x, y = -y;
        long long g = llgcd(x, y);
        x /= g, y /= g;
        if (y < 0)  x = -x, y = -y;
    }
    long long llgcd(long long x, long long y) const {
        long long t;
        while (x%y)
            t = x, x = y, y = t % y;
        return y;
    }
    Frac operator-(const Frac &a) const {
        long long va = 0, vb = a.y / llgcd(y, a.y) * y;
        va = vb / y * x - vb / a.y * a.x;
        return Frac(va, vb);
    }
    Frac operator+(const Frac &a) const {
        long long va = 0, vb = a.y / llgcd(y, a.y) * y;
        va = vb / y * x + vb / a.y * a.x;
        return Frac(va, vb);
    }
    Frac operator*(const Frac a) const {
        long long g1 = llgcd(x, a.y), g2 = llgcd(a.x, y);
        long long va = 0, vb = 0;
        va = (x / g1) * (a.x / g2);
        vb = (y / g2) * (a.y / g1);
        return Frac(va, vb);
    }
    Frac operator/(const Frac a) const {
        long long g1 = llgcd(y, a.y), g2 = llgcd(x, a.x);
        long long va = 0, vb = 0;
        va = (a.y / g1) * (x / g2);
        vb = (y / g1) * (a.x / g2);
        return Frac(va, vb);
    }
    bool operator==(const Frac &a) const {
        return x - a.x == 0 && y - a.y == 0;
    }
    bool operator<(const Frac &a) const {
        return x * a.y < a.x * y;
    }
    void print() {
    	if (y == 1)
    		printf("%lld", x);
    	else
        	printf("%lld/%lld", x, y);
    }
};

int t;

ll v1 , d1 , v2 , d2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> v1 >> d1 >> v2 >> d2 && v1)
    {
        printf("Case #%d: " , ++t);

        Frac p(d1 , v1);

        Frac q(d2 , v2);

        Frac r = (p + q) * Frac(1 , 2);

        if(p < q)
        {
            printf("You owe me a beer!");
        }
        else
        {
            printf("No beer for the captain.");
        }

        puts("");

        printf("Avg. arrival time: ");

        r.print();

        puts("");
    }

    return 0;
}
