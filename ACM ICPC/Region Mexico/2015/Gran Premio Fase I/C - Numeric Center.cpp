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

vector < ll > answers;

ll n;

/*
8
49
288
1681
9800
57121
332928
1940449
11309768
65918161
384199200
2239277041
13051463048
76069501249
443365544448
2584123765441
15061377048200
87784138523761
511643454094368
 */

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(6) << fixed;

	answers.emplace_back(8);
	answers.emplace_back(49);
	answers.emplace_back(288);
	answers.emplace_back(1681);
	answers.emplace_back(9800);
	answers.emplace_back(57121);
	answers.emplace_back(332928);
	answers.emplace_back(1940449);
	answers.emplace_back(11309768);
	answers.emplace_back(65918161);
	answers.emplace_back(384199200);
	answers.emplace_back(2239277041);
	answers.emplace_back(13051463048);
	answers.emplace_back(76069501249);
	answers.emplace_back(443365544448);
	answers.emplace_back(2584123765441);
	answers.emplace_back(15061377048200);
	answers.emplace_back(87784138523761);
	answers.emplace_back(511643454094368);

	if(fopen("InputArturoC.txt" , "r")) freopen("InputArturoC.txt" , "r" , stdin);

	while(cin >> n && n)
	{
		int pos = lower_bound(answers.begin() , answers.end() , n) - answers.begin();

		cout << pos + (answers[pos] <= n) << endl;
	}


	return 0;
}
