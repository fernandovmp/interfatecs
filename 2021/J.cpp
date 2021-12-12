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

vector<char> cd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    cd.resize(c);
    for (int i = 0; i < c; i++)
    {
        cin >> cd[i];
    }

    sort(cd.begin(), cd.end());
    int res = 0;
    do
    {
        int pt = 1, q = n;
        res = max(res, pt * q);
        for (int i = 0; i < (int)cd.size(); i++)
        {
            switch (cd[i])
            {
            case 'T':
                pt += 1;
                break;
            case 'R':
                pt += q / 2;
                break;
            case 'S':
                if (q == 0)
                    break;
                q -= 1;
                pt += pt / 2;
                break;
            }
            res = max(res, pt * q);
        }
    } while (next_permutation(cd.begin(), cd.end()));

    cout << res << "\n";

    return 0;
}
