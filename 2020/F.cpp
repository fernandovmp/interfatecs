// Autor: @fernandovmp

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int numeroAlunos, i, entrada, maisFrequente = -1, atual, frequencia, maiorFrequencia;
    double media, mediana, moda;
    while (scanf("%d", &numeroAlunos) != EOF)
    {
        media = mediana = moda = 0;
        int alunos[numeroAlunos];
        for (i = 0; i < numeroAlunos; i++)
        {
            scanf("%d", &entrada);
            alunos[i] = entrada;
            media += entrada;
        }
        media /= numeroAlunos;
        sort(alunos, alunos + numeroAlunos);
        int meio = numeroAlunos / 2;
        if (numeroAlunos % 2 == 0)
        {
            mediana = (alunos[meio - 1] + alunos[meio]) / 2.0;
        }
        else
        {
            mediana = alunos[meio];
        }
        maiorFrequencia = 0;
        vector<int> ff;
        map<int, int> frequencias;
        map<int, int>::iterator it;
        for (i = 0; i < numeroAlunos; i++)
        {
            it = frequencias.find(alunos[i]);
            if (it == frequencias.end())
            {
                frequencias.insert(make_pair(alunos[i], 1));
                maiorFrequencia = max(1, maiorFrequencia);
                continue;
            }
            it->second += 1;
            maiorFrequencia = max(it->second, maiorFrequencia);
        }
        for (it = frequencias.begin(); it != frequencias.end(); ++it)
        {
            if (it->second == maiorFrequencia)
            {
                ff.push_back(it->first);
            }
        }
        sort(ff.begin(), ff.end());
        int size = ff.size();
        printf("MODA=");
        for (i = 0; i < size; i++)
        {
            if (i < size - 1)
            {
                printf("%d,", ff[i]);
                continue;
            }
            printf("%d\n", ff[i]);
        }
        printf("MEDIA=%.2lf\n", media);
        printf("MEDIANA=%.2lf\n", mediana);
    }
    return 0;
}
