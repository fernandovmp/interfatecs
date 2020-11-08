// Autor: @JulioAugusto9, @fernandovmp
/*
Chegamos a essa solução após o tempo limite então não há certeza se ela realmente passaria no julgamento
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct P
{
    string pw;
    int tries;
    bool bloq;
};

typedef vector<set<char>> vsc;
typedef map<string, P> msp;

vsc tecla;
msp pess;

/*
Essa função provavelmente poderia ser removida se adapatasse o tratamento das variáveis 
para considerar que podem terminar '\n', provavelmente seria o mais adequado
*/
void removerQuebraLinha(char *string)
{
    int i = 0;
    while (string[i] != EOF)
    {
        if (string[i] == '\n')
        {
            string[i] = '\0';
            break;
        }
        i++;
    }
}

int main()
{
    int t;
    char c;
    char *nome, *pw;
    tecla.resize(12);
    for (int i = 0; i < 12; i++)
    {
        scanf("%d", &t);
        while (c = getchar(), c != '\n')
        {
            if (c != ';')
            {
                tecla[t - 1].insert(c);
            }
        }
    }

    P p;
    p.tries = 0;
    p.bloq = false;
    char line[120];
    while (fgets(line, 120, stdin))
    {
        nome = strtok(line, ";");
        pw = strtok(NULL, ";");
        removerQuebraLinha(pw);
        if (strcmp(nome, "fim") == 0 && strcmp(pw, "fim") == 0)
            break;
        p.pw = pw;
        pess[nome] = p;
    }
    while (fgets(line, 120, stdin))
    {
        nome = strtok(line, ";");
        if (pess.count(nome) == 0)
        {
            cout << nome << ": usuario inexistente\n";
            continue;
        }

        p = pess[nome];
        P *pp = &pess[nome];
        // pp->tries++;
        if (pp->tries >= 3)
        {
            cout << nome << ": usuario bloqueado" << endl;
            continue;
        }

        int i = 0, cont = 0;
        bool acc = true, acabou = false;
        c = '\0';
        char *e;
        while ((e = strtok(NULL, ";")) && e != NULL)
        {
            t = atoi(e);
            if (acabou)
            {
                acc = false;
                continue;
            }

            if (tecla[t - 1].count(p.pw[i++]) == 0)
            {
                acc = false;
            }
            else
                cont++;
            if (i == p.pw.size())
                acabou = true;
            //c = getchar();
        }
        if (cont != p.pw.size())
            acc = false;

        if (acc)
        {
            cout << nome << ": acesso concedido\n";
            pp->tries = 0;
        }
        else
        {
            pp->tries++;
            if (pp->tries >= 3)
            {
                cout << nome << ": usuario bloqueado" << endl;
                continue;
            }
            cout << nome << ": acesso negado\n";
        }
    }

    return 0;
}
