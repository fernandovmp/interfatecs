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
    cin.tie(0);

    int x, y;

    cin >> x >> y;

    if (x == y || x <= 0 || y <= 0)
    {
        cout << "ERRO" << endl;
    }
    else
    {
        cout << x _ y << endl;              // x y
        cout << y _ x << endl;              // y x
        cout << y _(x * -1) << endl;        // y -x
        cout << x _(y * -1) << endl;        // x -y
        cout << (x * -1) _(y * -1) << endl; // -x -y
        cout << (y * -1) _(x * -1) << endl; // -y -x
        cout << (y * -1) _ x << endl;       // -y x
        cout << (x * -1) _ y << endl;       // -x y
    }

    return 0;
}
