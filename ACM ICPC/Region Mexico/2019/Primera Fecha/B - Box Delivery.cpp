#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define ll long long
#define maxn 200010
using namespace std;

const ll z = 986444689;

/*int binomialCoeff(ll n, ll k)
{
    ll res = 1;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}*/

ll fact[maxn] , rfact[maxn];

ll nk(ll n , ll k)
{
    if(k > n)
    {
        return 0;
    }

    return fact[n] * rfact[k] % z * rfact[n - k] % z;
}

ll fpow(ll b , ll e)
{
    ll ret = 1;

    while(e > 0)
    {
        if(e & 1)
        {
            ret = (ret * b) % z;
        }

        b = b * b % z;

        e >>= 1;
    }

    return ret;
}

int t , n , k , actual;

string line;

bool ok;

int freq[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextB.txt" , "r")) freopen("ArturoTextB.txt" , "r" , stdin);

    fact[0] = 1;

    for(ll i = 1; i < maxn; i++)
    {
        fact[i] = fact[i - 1] * i % z;
    }

    rfact[maxn - 1] = fpow(fact[maxn - 1] , z - 2);

    for(ll i = maxn - 2; i >= 0; i--)
    {
        rfact[i] = rfact[i + 1] * (i + 1) % z;
    }

    getline(cin , line);

    t = stoi(line);

    while(t--)
    {
        getline(cin , line);

        n = 0 , k = 0;

        ok = true;

        memset(freq , 0 , sizeof(freq));

        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == ' ')
            {
                ok = false;
            }
            else
            {
                if(line[i] >= '0' && line[i] <= '9')
                {
                    if(ok)
                    {
                        n *= 10;

                        n += (line[i] - '0');
                    }
                    else
                    {
                        k *= 10;

                        k += (line[i] - '0');
                    }
                }
            }
        }

        //cout << "n = " << n << " k = " << k << endl;

        //cout << "n k line = " << line << endl;

        getline(cin , line);

        //cout << "super line = " << line << endl;

        actual = 0;

        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == ' ')
            {
                freq[actual] = 1;

                actual = 0;
            }
            else
            {
                if(line[i] >= '0' && line[i] <= '9')
                {
                    actual *= 10;

                    actual += (line[i] - '0');
                }
            }
        }

        freq[actual] = 1;

        getline(cin , line);

        actual = 0;

        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == ' ')
            {
                freq[actual] = 2;

                actual = 0;
            }
            else
            {
                if(line[i] >= '0' && line[i] <= '9')
                {
                    actual *= 10;

                    actual += (line[i] - '0');
                }
            }
        }

        freq[actual] = 2;

        for(int i = 1; i <= n; i++)
        {
            k -= freq[i];
        }

        cout << nk(n + k - 1 , n - 1) << endl;
    }

    return 0;
}
