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
#define maxp 2000005
using namespace std;

int maxn;

ll target , a[50] , X[maxp] , Y[maxp] , ans;

void calcsubarray(ll x[], int n , int c)
{
    for (int i = 1; i < (1 << n); i++)
    {
        ll s = 0;

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                s += a[j + c];
			}
		}

        x[i] = s;
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if(fopen("InputArturoE.txt" , "r")) freopen("InputArturoE.txt" , "r" , stdin);

	while(cin >> maxn >> target)
	{
		for(int i = 0; i < maxn; i++)
		{
			cin >> a[i];
		}

		ans = 0;

		calcsubarray(X , maxn / 2 , 0);

		calcsubarray(Y , maxn - maxn / 2 , maxn / 2);

		int szx = 1 << (maxn / 2);

		int szy = 1 << (maxn - maxn / 2);

		sort(Y + 1 , Y + szy);

		for(int i = 1; i < szx; i++)
		{
			ans += (X[i] == target);

			int pos = lower_bound(Y + 1 , Y + szy, target - X[i]) - Y;

			while(pos < szy && Y[pos] == (target - X[i]))
			{
				ans++;
				pos++;
			}
		}

		for(int i = 1; i < szy; i++)
		{
			ans += (Y[i] == target);
		}

		cout << ans << endl;

		/*cout << "x" << endl;

		for(int i = 1; i < szx; i++)
		{
			cout << X[i] << " ";
		}

		cout << endl << "y" << endl;

		for(int i = 1; i < szy; i++)
		{
			cout << Y[i] << " ";
		}

		cout << endl;*/
	}


	return 0;
}
