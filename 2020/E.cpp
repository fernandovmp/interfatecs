// Autor: @fernandovmp

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int qtdeProcessos, chegada, execucao, i, intstante = 0;
    double tme = 0, tmt = 0;
    scanf("%d", &qtdeProcessos);
    for (i = 0; i < qtdeProcessos; i++)
    {
        scanf("%d %d", &chegada, &execucao);
        tme += intstante - chegada;
        intstante += execucao;
        tmt += intstante - chegada;
    }
    tme /= qtdeProcessos;
    tmt /= qtdeProcessos;
    printf("TME:%.1lf\n", tme);
    printf("TMT:%.1lf\n", tmt);
    return 0;
}
