// Autor: @JulioAugusto9

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int, string> > vis;
typedef vector<ii> vii;
typedef map<string, int> msi;
typedef vector<vector<int> > vvi;

vis nome;
msi id;
vvi g;
vi d;

void bfs(int V, int s) {
    d[s] = 0; // distance from source s to s is 0
    queue<int> q; q.push(s); // start from source
    while (!q.empty()) {
        int u = q.front(); q.pop(); // queue: layer by layer!
        for (int j = 0; j < (int)g[u].size(); j++) {
            int v = g[u][j]; // for each neighbor of u
            if (d[v] == INF) { // if v.first is unvisited + reachable
                d[v] = d[u] + 1; // make d[v.first] != INF to flag it
                q.push(v); // enqueue v.first for the next iteration
            }
        }
    }
}

int main() {
    int N, a, b, V=0, sara=-1;
    cin>>N;
    string s1, s2, lixo;
    g.resize(50);
    while (N--) {
        cin>>s1>>lixo>>s2;

        if (id.count(s1) == 0) {
            id[s1] = V;
            nome.push_back({0,s1});
            a = V++;
        }
        else {
            a = id[s1];
        }

        if (id.count(s2) == 0) {
            id[s2] = V;
            nome.push_back({0,s2});
            b = V++;
        }
        else {
            b = id[s2];
        }

        g[a].push_back(b);
        g[b].push_back(a);

        if (sara == -1) {
            if (s1 == "Saracura")
                sara = a;
            else if (s2 == "Saracura")
                sara = b;
        }
    }
    d.assign(V, INF);
    bfs(V, sara);
    
    for (int i = 0; i < V; i++)
    {
        nome[i].first = d[i];
    }

    sort(nome.begin(), nome.end());
    
    for (int i = 0; i < V; i++)
    {
        if (nome[i].first == 0)
            continue;
        //printf("%s: %s", nome[i].second, nome[i].first == INF ? "infinito" : to_string(nome[i].first).c_str());
        cout << nome[i].second << ": " << (nome[i].first == INF ? "infinito" : to_string(nome[i].first)) << "\n";
    }

    return 0;
}
