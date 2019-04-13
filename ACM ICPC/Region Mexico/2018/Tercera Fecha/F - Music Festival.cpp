#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct presentacion
{
    int inicio , fin , coinciden;

    bool operator < (const presentacion &otrapresentacion) const
    {
        return fin < otrapresentacion.fin;
    }
};

int n , m , ans;

vector < vector < presentacion > > escenarios;

vector < pair < int , int > > presentaciones;

vector < pair < int , int > > dp[(1 << 10) + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    escenarios.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> m;

        escenarios[i].resize(m);

        for(auto &it : escenarios[i])
        {
            cin >> it.inicio >> it.fin >> it.coinciden;

            presentaciones.emplace_back(it.fin , i);
        }

        sort(escenarios[i].rbegin() , escenarios[i].rend());
    }

    sort(presentaciones.rbegin() , presentaciones.rend());

    int max_perm = (1 << n);

    dp[0].emplace_back(0 , 0);

    while(!presentaciones.empty())
    {
        int presentacion_fin_mas_reciente = presentaciones.back().second;

        presentaciones.pop_back();

        for(int i = 1; i < max_perm; i++)
        {
            if((i & (1 << presentacion_fin_mas_reciente)) == 0)
            {
                continue;
            }

            // Esto quiere decir que de todas las permutaciones posibles debemos ver si la presentacion que termina mas pronto pertenece a esta permutacion

            ans = -(1 << 30);

            auto &presentacion_mas_reciente = escenarios[presentacion_fin_mas_reciente].back();

            for(auto &it : dp[i])
            {
                if(it.first <= presentacion_mas_reciente.inicio)
                {
                    ans = max(ans , it.second + presentacion_mas_reciente.coinciden);
                }
            }

            for(auto &it : dp[i ^ (1 << presentacion_fin_mas_reciente)])
            {
                if(it.first <= presentacion_mas_reciente.inicio)
                {
                    ans = max(ans , it.second + presentacion_mas_reciente.coinciden);
                }
            }


            if(ans != -(1 << 30))
            {
                dp[i].emplace_back(presentacion_mas_reciente.fin , ans);
            }
        }

        escenarios[presentacion_fin_mas_reciente].pop_back();
    }

    ans = -(1 << 30);

    for(auto &it : dp[max_perm - 1])
    {
        ans = max(ans , it.second);
    }

    if(ans < 0)
    {
        cout << -1 << endl;

        return 0;
    }

    cout << ans << endl;

    return 0;
}
