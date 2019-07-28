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
using namespace std;

// C function for extended Euclidean Algorithm (used to
// find modular inverse.
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
ll modInverse(ll b, ll m)
{
    ll x, y; // used in extended GCD algorithm
    ll g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;

    // m is added to handle negative x
    return (x%m + m) % m;
}

// Function to compute a/b under modlo m
ll modDivide(ll a, ll b, ll m)
{
    a = a % m;
    ll inv = modInverse(b, m);
    if (inv == -1)
       return -1;
    else
       return (inv * a) % m;
}

template < typename T > T modpow(T base , T exp , T modulus)
{
  base %= modulus;

  T result = 1;

  while (exp > 0)
  {
    if (exp & 1)
    {
        result = (result * base) % modulus;
    }

    base = (base * base) % modulus;

    exp >>= 1;
  }

  return result;
}

const ll z = 1e9 + 7;

int t;

ll m , n , p , q;

ll numerador , denominador , sumofdivisors , suma;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(3) << fixed;

    if(fopen("ArturoTextJ.txt" , "r")) freopen("ArturoTextJ.txt" , "r" , stdin);

    cin >> t;

    while(t--)
    {
        cin >> m >> n >> p >> q;

        numerador = modpow(p , q + 1 , z);

        numerador = (numerador - 1 + z) % z;

        denominador = ((p % z) - 1 + z) % z;

        sumofdivisors = modDivide(numerador , denominador , z);

        sumofdivisors = ((sumofdivisors % z) * 2) % z;

        n %= z;

        m %= z;

        suma = (n + m) % z;

        sumofdivisors = (sumofdivisors * suma) % z;

        cout << sumofdivisors << endl;
    }

    return 0;
}
