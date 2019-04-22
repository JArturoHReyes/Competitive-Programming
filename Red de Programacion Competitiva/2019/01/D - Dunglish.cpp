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

string input[30];

string d , e , c;

int n , m;

ll total , totalcorr;

map < string , string > corr , incorr;

map < string , ll > freqcorr , freqincorr;

vector < string > answers;

bool correct , justone;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(fopen("InputArturoD.txt" , "r")) freopen("InputArturoD.txt" , "r" , stdin);

	total = 1LL , totalcorr = 1LL , correct = true , justone = true;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	cin >> m;

	for(int i = 0; i < m; i++)
	{
		cin >> d >> e >> c;

		if(c == "correct")
		{
			corr[d] = e;

			freqcorr[d]++;
		}
		else
		{
			incorr[d] = e;

			freqincorr[d]++;
		}
	}

	for(int i = 0; i < n; i++)
	{
		totalcorr *= freqcorr[input[i]];

		total *= (freqcorr[input[i]] + freqincorr[input[i]]);

		if(freqcorr[input[i]] + freqincorr[input[i]] > 1)
		{
			justone = false;
		}

		if(justone && freqcorr[input[i]] == 0)
		{
			correct = false;
		}

		if(justone)
		{
			if(freqcorr[input[i]])
			{
				answers.push_back(corr[input[i]]);
			}
			else
			{
				answers.push_back(incorr[input[i]]);
			}
		}
	}

	if(justone)
	{
		for(int i = 0; i < answers.size() - 1; i++)
		{
			cout << answers[i] << " ";
		}

		cout << answers[answers.size() - 1] << endl;

		if(correct)
		{
			cout << "correct" << endl;
		}
		else
		{
			cout << "incorrect" << endl;
		}
	}
	else
	{
		cout << totalcorr << " correct" << endl;

		cout << (total - totalcorr) << " incorrect" << endl;
	}
	
	return 0;
}
