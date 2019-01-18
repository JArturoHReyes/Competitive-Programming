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

int a[20] , arr[20];

ll n , sum , ans , actualsum; int k , cnt1;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(fopen("InputArturoK.txt" , "r")) freopen("InputArturoK.txt" , "r" , stdin);
	
	while(cin >> n >> k)
	{
		//cout << "N = " << n << endl;
		cnt1 = 0;
		
		sum = n;
		
		for(int i = 0; i < k; i++)
		{
			cin >> a[i];
			
			if(n & 1ll << a[i])
			{
				cnt1++;
				
				sum -= (1ll << a[i]);
			}
		}
		
		for(int i = 0; i < k - cnt1; i++)
		{
			arr[i] = 0;
		}
		
		for(int i = k - cnt1; i < k; i++)
		{
			arr[i] = 1;
		}
		
		ans = 0;
		
		do
		{
			actualsum = sum;
			
			for(int i = 0; i < k; i++)
			{
				if(arr[i])
				{
					actualsum += (1ll << a[i]);
				}
			}
			
			if(actualsum % 7 == 0)
			{
				ans = max(ans , actualsum);
			}
			
		}while(next_permutation(arr , arr + k));
		
		cout << ans << endl;
	}
	
	return 0;
}
