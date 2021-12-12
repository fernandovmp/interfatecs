#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<ll> vll;

const int M = 1e9 + 7;
#define _ << " " <<

map<char, int> ana, win;

bool eq()
{
    bool eq = true;
    for (auto pr : ana)
    {
        char ch = pr.first;
        int qtd = pr.second;
        if (!(win.count(ch) > 0 && win[ch] == qtd))
        {
            eq = false;
            break;
        }
    }
    return eq;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    string s, p;
    cin >> tc;
    while (tc--)
    {
        cin >> s >> p;
        if (p.size() > s.size())
        {
            cout << "ERRO\n";
            continue;
        }

        int i;
        for (i = 0; i < int(p.size()); i++)
        {
            ana[p[i]]++;
            win[s[i]]++;
        }

        int cnt = 0;
        if (eq())
            cnt++;
        int j = 0;
        for (; i < int(s.size()); i++, j++)
        {
            win[s[i]]++;
            win[s[j]]--;
            if (eq())
                cnt++;
        }

        cout << cnt << "\n";

        win.clear();
        ana.clear();
    }

    return 0;
}
