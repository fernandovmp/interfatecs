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

struct cmp
{
    string nom;
    ll a, b, c;
};

vector<cmp> cm;

bool byT1(cmp x, cmp y)
{
    if (x.a == y.a)
        return x.nom < y.nom;
    return x.a < y.a;
}

bool byT2(cmp x, cmp y)
{
    if (x.b == y.b)
        return x.nom < y.nom;
    return x.b < y.b;
}

bool byCH(cmp x, cmp y)
{
    if (x.c == y.c)
        return x.nom < y.nom;
    return x.c < y.c;
}

void prin(string pt)
{
    cout << pt _ cm[0].nom _ cm[1].nom _ cm[2].nom << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string nome;
    ll a, b, c;
    while (cin >> nome, !cin.eof())
    {
        cin >> a >> b >> c;
        cm.push_back({nome, a, b, c});
    }

    sort(cm.begin(), cm.end(), byT1);
    prin("T1");
    sort(cm.begin(), cm.end(), byT2);
    prin("T2");
    sort(cm.begin(), cm.end(), byCH);
    prin("CHEGADA");

    return 0;
}
