// Autor: @fernandovmp

#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX

vector<vector<int>> adjList;
vector<int> visitados;

bool ehBipartido(int origem, int numeroVertices)
{
    queue<int> fila;
    fila.push(origem);
    vector<int> cores(numeroVertices, INF);
    visitados[origem] = 1;
    cores[origem] = 0;
    while (!fila.empty())
    {
        int proximo = fila.front();
        fila.pop();
        for (int i = 0; i < adjList[proximo].size(); i++)
        {
            int vertice = adjList[proximo][i];
            if (cores[vertice] == INF)
            {
                cores[vertice] = 1 - cores[proximo];
                fila.push(vertice);
            }
            else if (cores[vertice] == cores[proximo])
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int convidados, inimizadeOrigem, inimizadeDestino, i;
    bool podeRealizarFesta;
    scanf("%d", &convidados);

    adjList.clear();
    adjList.resize(convidados);
    visitados.clear();
    visitados.resize(convidados, -1);

    while (scanf("%d %d", &inimizadeOrigem, &inimizadeDestino) != EOF)
    {
        inimizadeOrigem--;
        inimizadeDestino--;
        adjList[inimizadeOrigem].push_back(inimizadeDestino);
        adjList[inimizadeDestino].push_back(inimizadeOrigem);
    }

    podeRealizarFesta = true;
    for (int i = 0; i < convidados; i++)
        if (visitados[i] == -1)
        {
            podeRealizarFesta = podeRealizarFesta && ehBipartido(i, convidados);
        }

    if (podeRealizarFesta)
    {
        printf("FESTA!\n");
    }
    else
    {
        printf("Lascou...\n");
    }

    return 0;
}
