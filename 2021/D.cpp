#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int32_t> lista;
    int32_t a, n = 0;
    while (cin >> a)
    {
        n += a;
        lista.push_back(a);
    }
    cout << fixed << setprecision(3);
    for (int i = 0; i < lista.size(); i++)
    {
        double valor = (lista[i] / (double)n);
        cout << valor << '\n';
    }
    return 0;
}
