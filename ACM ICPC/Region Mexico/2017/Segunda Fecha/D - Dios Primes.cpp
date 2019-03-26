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
#define maxn 1010
#define ll long long
using namespace std;

vector < ll > primes;

int t;

ll a , b;

void precal()
{
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	primes.push_back(7);
	primes.push_back(37);
	primes.push_back(73);
	primes.push_back(313);
	primes.push_back(347);
	primes.push_back(353);
	primes.push_back(373);
	primes.push_back(383);
	primes.push_back(743);
	primes.push_back(797);
	primes.push_back(3467);
	primes.push_back(7643);
	primes.push_back(34673);
	primes.push_back(37643);
	primes.push_back(76367);
	primes.push_back(79397);
	primes.push_back(7693967);
	primes.push_back(799636997);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(fopen("InputArturoF.txt" , "r")) freopen("InputArturoF.txt" , "r" , stdin);

	precal();

	cin >> t;

	while(t--)
	{
		cin >> a >> b;

		auto low = lower_bound(primes.begin() , primes.end() , a);

		auto high = upper_bound(primes.begin() , primes.end() , b);

		cout << high - low << endl;
	}

	return 0;
}
