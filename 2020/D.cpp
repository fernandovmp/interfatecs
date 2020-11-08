// Autor: @fernandovmp

#include <bits/stdc++.h>

using namespace std;

bool comparador(const pair<pair<int, char>, int> &a, const pair<pair<int, char>, int> &b)
{
    if (a.first.first > b.first.first)
    {
        return false;
    }
    if (a.first.first < b.first.first)
    {
        return true;
    }
    return a.first.second > b.first.second;
}

int main(int argc, char const *argv[])
{
    int numeroPares, d, e;
    map<pair<int, char>, int> paresDistintos;
    vector<pair<pair<int, char>, int>> listPares;
    scanf("%d", &numeroPares);
    for (int i = 0; i < numeroPares; i++)
    {
        scanf("%d %d", &e, &d);
        pair<int, char> esquerdo = make_pair(e, 'E');
        pair<int, char> direito = make_pair(d, 'D');
        map<pair<int, char>, int>::iterator it = paresDistintos.find(esquerdo), it2 = paresDistintos.find(direito);
        if (it == paresDistintos.end())
        {
            paresDistintos.insert(make_pair(esquerdo, 1));
        }
        else
        {
            it->second++;
        }
        if (it2 == paresDistintos.end())
        {
            paresDistintos.insert(make_pair(direito, 1));
        }
        else
        {
            it2->second++;
        }
    }
    int cont = 0;
    for (map<pair<int, char>, int>::iterator iter = paresDistintos.begin(); iter != paresDistintos.end(); ++iter)
    {
        if (iter->second == 1)
            continue;
        listPares.push_back(*iter);
    }
    sort(listPares.begin(), listPares.end(), comparador);
    for (vector<pair<pair<int, char>, int>>::iterator iter = listPares.begin(); iter != listPares.end(); ++iter)
    {
        printf("%d %c %d\n", iter->first.first, iter->first.second, iter->second - 1);
        cont++;
    }
    if (cont == 0)
    {
        printf("SEM TROCAS DESTA VEZ\n");
    }
    return 0;
}
