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

vector<vector<char>> mat, moves;
vector<vi> vis, dist;
vector<vii> parents;

bool valid(int i, int j, int n, int m)
{
    if (i < 0 || i >= n)
        return false;
    if (j < 0 || j >= m)
        return false;
    if (vis[i][j])
        return false;
    if (mat[i][j] == '0')
        return false;
    return true;
}

ii child(int i, int j, int k, int l, char move)
{
    dist[k][l] = dist[i][j] + 1;
    parents[k][l] = {i, j};
    moves[k][l] = move;
    vis[k][l] = 1;
    return {k, l};
}

void bfs(ii start, ii end, int n, int m)
{
    queue<ii> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    vis[start.first][start.second] = 1;
    while (!q.empty())
    {
        if (q.front() == end)
            break;
        int i = q.front().first, j = q.front().second;
        q.pop();
        if (valid(i + 1, j, n, m))
            q.push(child(i, j, i + 1, j, 'D'));
        if (valid(i - 1, j, n, m))
            q.push(child(i, j, i - 1, j, 'U'));
        if (valid(i, j + 1, n, m))
            q.push(child(i, j, i, j + 1, 'R'));
        if (valid(i, j - 1, n, m))
            q.push(child(i, j, i, j - 1, 'L'));
    }
}

void printPath(ii end)
{
    vector<ii> path;
    //cout << dist[end.first][end.second] << "\n";
    while (dist[end.first][end.second] != 0)
    {
        int i, j;
        tie(i, j) = end;
        path.push_back(end);
        end = parents[i][j];
    }
    path.push_back(end);
    reverse(path.begin(), path.end());
    for (int i = 0; i < int(path.size()); i++)
    {
        cout << path[i].first + 1 << " " << path[i].second + 1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    ii start, end;
    start = {a - 1, b - 1};
    end = {c - 1, d - 1};
    mat.resize(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    dist.resize(n, vi(n, INT_MAX));
    parents.resize(n, vii(n));
    moves.resize(n, vector<char>(n));
    vis.resize(n, vi(n, 0));
    bfs(start, end, n, n);

    //cout<< dist[end.first][end.second] << endl;

    if (dist[end.first][end.second] == INT_MAX)
    {

        return 0;
    }

    printPath(end);

    return 0;
}
