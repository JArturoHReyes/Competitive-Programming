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

ll b , t , n , a;

ll need[25];

vector < ll > tr[110];

ll ans;

ll go(ll bitmask)
{
    for(int i = t; i--;)
    {
        bool ok = false;

        for(ll g : tr[i])
        {
            if(bitmask & (1LL << g))
            {
                ok = true;

                break;
            }
        }

        if(!ok)
        {
            return -1LL;
        }
    }

    ll ret = 0;

    for(ll k = b; k--;)
    {
        if(!(bitmask&(1LL<<k)))
        {
            ret += need[k];
        }
    }

    return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if(fopen("InputArturoJ.txt" , "r")) freopen("InputArturoJ.txt" , "r" , stdin);

    cin >> b;

    for(int i = 0; i < b; i++)
    {
        cin >> need[i];
    }

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        cin >> n;

        for(int j = 0; j < n; j++)
        {
            cin >> a;

            tr[i].push_back(a - 1);
        }
    }

    for(ll i = (1LL << b); i--;)
    {
        ans = max(ans , go(i));
    }

    cout << ans << endl;

	return 0;
}
