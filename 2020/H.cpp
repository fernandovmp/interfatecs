// Autor: @fernandovmp

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int vagas, numeroPartidos;
    scanf("%d %d", &vagas, &numeroPartidos);
    uint64_t totalVotos = 0;
    int votos[numeroPartidos];
    for (int i = 0; i < numeroPartidos; i++)
    {
        scanf("%d", &votos[i]);
        totalVotos += votos[i];
    }

    //Quociente Eleitoral
    double quocienteEleitoral = round((double)totalVotos / (double)vagas);

    //Quociente Partidario
    int vagasParaOcupar = 0;
    int partidoParaReceberVaga = -1;
    double media = 0;
    int quocientePartidario[numeroPartidos];
    for (int i = 0; i < numeroPartidos; i++)
    {
        quocientePartidario[i] = (int)(votos[i] / quocienteEleitoral);
        vagasParaOcupar += quocientePartidario[i];
        if (quocientePartidario[i] == 0)
            continue;
        double m = votos[i] / (double)(quocientePartidario[i] + 1);
        if (m > media)
        {
            media = m;
            partidoParaReceberVaga = i;
        }
    }

    //Distribuição de vagas
    while (vagas - vagasParaOcupar > 0)
    {
        quocientePartidario[partidoParaReceberVaga] += 1;
        vagasParaOcupar++;
        if (vagas - vagasParaOcupar == 0)
            break;
        partidoParaReceberVaga = -1;
        media = 0;
        for (int i = 0; i < numeroPartidos; i++)
        {
            if (quocientePartidario[i] == 0)
                continue;
            double m = votos[i] / (quocientePartidario[i] + 1);
            if (m > media)
            {
                media = m;
                partidoParaReceberVaga = i;
            }
        }
    }

    //Saida
    printf("%d %.0lf\n", totalVotos, quocienteEleitoral);
    for (int i = 0; i < numeroPartidos; i++)
    {
        printf("Partido %d: %d\n", i + 1, quocientePartidario[i]);
    }
    return 0;
}
