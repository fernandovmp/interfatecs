// Autor: @JulioAugusto9

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

#define MAX_N 100100 
#define MAX_Q 1100

int Q;
vi p;
int memo[MAX_Q][MAX_N];

int val(int i, int P) {
    if (P == 0) return 1;
    if (P < 0 || i == Q) return 0;
    if (memo[i][P] != -1) return memo[i][P];
    if (val(i+1, P) == 1) return 1;
    if (val(i+1, P-p[i]) == 1) return 1;
    return (memo[i][P] = 0);
}

int main() {
    int N;
    cin>>N>>Q;
    p.resize(N);
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < Q; i++)
    {
        cin>>p[i];
    }
    int m = val(0,N);
    if (m) {
        printf("SIM\n");
    }
    else {
        printf("NAO\n");
    }
    return 0;
}
