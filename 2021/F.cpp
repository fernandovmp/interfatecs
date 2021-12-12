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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    bool rua = false;
    int res = 0;
    for (int i = 3; i <= n; i += 2)
    {
        if (!rua)
        {
            res += (i - 2) * 4 + 2;
        }
        rua = !rua;
    }

    cout << res << "\n";

    return 0;
}
