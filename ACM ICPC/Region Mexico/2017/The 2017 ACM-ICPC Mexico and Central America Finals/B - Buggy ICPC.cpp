#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(false) , cin.tie(nullptr);
#define in freopen("input.txt" , "r" , stdin);
#define out freopen("output.txt" , "w" , stdout);
#define endl '\n'
#define tle cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
using namespace std;

vector < int > v;

bool isvowel(char s)
{
    if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
    {
        return true;
    }

    return false;
}

int main()
{
    opt;

    string str;

    while(cin >> str)
    {
       int vowels = 0;

       for(int i = 0; i < str.length(); i++)
       {
           if(isvowel(str[i]))
           {
               vowels++;
           }
       }

       if(vowels == 0)
       {
          cout << 1 << endl;
          continue;
       }

       if(!isvowel(str[0]))
       {
           cout << 0 << endl;
           continue;
       }

       if(vowels == 1)
       {
           cout << str.length() << endl;
           continue;
       }

       v.clear();

       for(int i = 0; i < str.length(); i++)
       {
           if(isvowel(str[i]))
           {
               int cont = 0;
               i++;

               while(i < str.length() && !isvowel(str[i]))
               {
                   cont++;
                   i++;
               }

               if(i == str.length())
               {
                   break;
               }

               v.push_back(cont);
               i--;
           }
       }

       cout << v[v.size() / 2] + 1 << endl;
    }

    return 0;

}
