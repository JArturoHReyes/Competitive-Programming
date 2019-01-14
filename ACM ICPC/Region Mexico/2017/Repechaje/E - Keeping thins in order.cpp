#include<bits/stdc++.h>
using namespace std;

int main()
{
    string x;

    while(getline(cin , x) && x != ".")
    {
        int i = 0;
        string number;
        string word;
        vector < string > wordsnolower;
        vector < long long > elements;
        vector < long long > numbers;
        vector < pair < string , int > > words;

        while(x[i] != '.' && i < x.length())
        {
           if(x[i] == ',' || x[i] == ' ')
           {
               number.erase();
               word.erase();
           }
           else
           {
               if(x[i] == '-' || (x[i] >= '0' && x[i] <= '9'))
               {
                   while(x[i] != '.' && x[i] != ',')
                   {
                      number += x[i++];
                   }

                   elements.push_back(0);
                   long long t = atoll(number.c_str());
                   numbers.push_back(t);
               }
               else
               {
                   while(x[i] != '.' && x[i] != ',')
                   {
                       word += x[i++];
                   }
                   elements.push_back(1);
                   wordsnolower.push_back(word);
                   string notlower;
                   for(int i = 0; i < word.size(); i++)
                   {
                       char g = tolower(word[i]);
                       notlower += g;
                   }
                   words.push_back(make_pair(notlower ,wordsnolower.size() - 1));
               }
           }

           i++;
        }

        sort(numbers.begin() , numbers.end());
        sort(words.begin() , words.end());
        int posofnumbers = 0;
        int posofwords = 0;

        for(int j = 0; j < elements.size(); j++)
        {
            if(elements[j])
            {
               pair < string , int > f = words[posofwords++];
               cout <<  wordsnolower[f.second];
            }
            else
            {
                cout << numbers[posofnumbers++];
            }

            if(posofwords != words.size() || posofnumbers != numbers.size())
            {
                cout << ", ";
            }

        }

        cout << "." << endl;

    }

    return 0;
}
