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

int n , start;

ll s;

char c;

string up , mid , down , x;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if(fopen("InputArturoE.txt" , "r")) freopen("InputArturoE.txt" , "r" , stdin);

	while(cin >> n)
	{
	    cin >> s >> c;

		cin >> up;

		mid = "";

		do
        {
            cin >> x;

            mid += x;

            if(mid.size() != 2 * n + 1)
            {
                mid += ' ';
            }

        }while(mid.size() != 2 * n + 1);

		cin >> down;

		if(c == 'L')
        {
            start = s % n;
        }
        else
        {
            s %= n;

            start = n - s;
        }

		cout << up << endl;

		for(int i = 2 * start; i < 2 * n + 1; i++)
        {
            cout << mid[i];
        }

        for(int i = 1; i <= 2 * start; i++)
        {
            cout << mid[i];
        }

        cout << endl;

		cout << down << endl;
	}

	return 0;
}
