#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visitados;
set<int> terroristas;

bool bfs(int32_t origem, int32_t destino)
{
    queue<int> fila;
    int v, atual;
    fila.push(origem);
    if (terroristas.count(origem) > 0 || terroristas.count(destino) > 0)
    {
        return false;
    }
    while (!fila.empty())
    {
        v = fila.front();
        fila.pop();
        visitados[v] = true;
        if (v == destino)
        {
            return true;
        }
        for (int i = 0; i < adj[v].size(); i++)
        {
            atual = adj[v][i];
            if (!visitados[atual] && terroristas.count(atual) == 0)
            {
                fila.push(atual);
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, refens, saida, t, a, b, p;
    cin >> n >> refens >> saida;
    saida--;
    refens--;
    cin >> t;
    adj.resize(n);
    visitados.resize(n);
    for (int i = 0; i < n; i++)
    {
        adj[i] = vector<int>();
        visitados[i] = false;
    }
    while (t--)
    {
        cin >> a;
        a--;
        terroristas.insert(a);
    }
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (bfs(saida, refens))
    {
        cout << "PROSSEGUIR";
    }
    else
    {
        cout << "ABORTAR";
    }
    cout << '\n';

    return 0;
}
