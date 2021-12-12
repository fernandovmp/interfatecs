#include <bits/stdc++.h>

using namespace std;

typedef struct Placa
{
    int valor;
    bool ativo;
    string placa;
} placa_t;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char c;
    int numero;
    int vagas = 15;
    string entrada;
    vector<placa_t> placas;
    placas.resize(15);
    for (int i = 0; i < 15; i++)
    {
        placas[i].ativo = false;
    }
    while (cin >> entrada)
    {
        placa_t placa;
        placa.placa = entrada;
        placa.valor = 0;
        for (int i = 0; i < 7; i++)
        {
            c = entrada[i];
            placa.valor += (int)c;
        }
        placa.valor = placa.valor % 15;
        if (!placas[placa.valor].ativo)
        {
            vagas--;
            placa.ativo = true;
            placas[placa.valor] = placa;
        }
    }
    for (int i = 0; i < 15; i++)
    {
        auto p = placas[i];
        if (p.ativo)
        {
            cout << (i + 1) << " " << p.placa << '\n';
        }
    }
    return 0;
}
