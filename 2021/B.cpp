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

    int casos, l1, l2, l3;
    string entradas;

    cin >> casos;

    while (casos--)
    {
        l1 = l2 = l3 = -1; // esquerda
        cin >> entradas;

        for (char const &c : entradas)
        {

            if (c == 'A')
            {
                if (l1 == 0)
                {
                    l1 = -1;

                    if (l2 == -1)
                    {
                        l2 = 0;
                        cout << 'D';
                    }
                    else
                    {
                        l2 = -1;
                        cout << 'E';
                    }
                }
                else
                {
                    l1 = 0;
                    cout << 'D';
                }
            }

            if (c == 'B')
            {
                if (l2 == -1)
                {
                    l2 = 0;
                    cout << 'D';
                }
                else
                {
                    l2 = -1;
                    cout << 'E';
                }
            }

            if (c == 'C')
            {
                if (l3 == -1)
                {
                    l3 = 0;

                    if (l2 == -1)
                    {
                        l2 = 0;
                        cout << 'D';
                    }
                    else
                    {
                        l2 = -1;
                        cout << 'E';
                    }
                }
                else
                {
                    l3 = -1;
                    cout << 'E';
                }
            }
        }

        cout << endl;
    }

    return 0;
}
