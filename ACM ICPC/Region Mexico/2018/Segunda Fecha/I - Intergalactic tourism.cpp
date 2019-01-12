#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(false) , cin.tie(0);
#define in freopen("input.txt" , "r" , stdin);
#define out freopen("output.txt" , "w" , stdout);
#define endl '\n'
#define c(x) cout.precision(x) , cout << fixed;
#define tle cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
using namespace std;

int main()
{
    opt;

    int t , numberofplanets , numberofrestrictions , restriction;

    cin >> t;

     //scanf("%d" , &t);

    while(t--)
    {
        cin >> numberofplanets;

         //scanf("%d" , &numberofplanets);

        vector < vector < int > > restrictions(numberofplanets);

        for(int i = 0; i < numberofplanets; i++)
        {
            cin >> numberofrestrictions;

             //scanf("%d" , &numberofrestrictions);

            for(int j = 0; j < numberofrestrictions; j++)
            {
                cin >> restriction;

                 //scanf("%d" , restriction);

                restrictions[i].push_back(restriction);
            }
        }

        vector < int > outputs;

        for(int i = 0; i < numberofplanets; i++)
        {
            outputs.push_back(i);
        }

        do
        {

            set < int > visited;

            for(auto planet : outputs)
            {
               for(int i = 0; i < restrictions[planet].size(); i++)
               {
                   if(!visited.count(restrictions[planet][i]))
                   {
                       goto noimprimir;
                   }
               }

               visited.insert(planet);

            }

            for(auto planet : outputs)
            {
                cout << planet << " ";

                // printf("%d " , planet);
            }

           // printf("\n");

            cout << endl;

            noimprimir: numberofplanets =  2;


        }while(next_permutation(outputs.begin() , outputs.end()));
    }

    return 0;

}
