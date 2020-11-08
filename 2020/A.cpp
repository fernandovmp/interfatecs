// Autor: @JulioAugusto9

#include <bits/stdc++.h>
using namespace std;

typedef vector<char[110]> vvc;
char n[1000000][110];

int cmp(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int main() {
    int t = 0;
    char s[110], sub[110];
    while (scanf("%[^\n]", s) != EOF) {
        scanf("%*c");
        //printf("%s\n", s);
        int i=1, k=1, ultima = strlen(s)-1;
        // while (s[ultima] == ' ') {
        //     s[ultima--] = 0;
        // }
        while (ultima >= 0 && s[ultima] != ' ') {
            ultima--;
        }
        //printf("%d %c\n", ultima, s[ultima]);
        sub[0] = s[0];
        while (s[i] != 0) {
            if (s[i-1] == ' ' && i-1 != ultima) {
                sub[k++] = s[i];
                sub[k++] = '.';
                while (s[i] != ' ') i++;
                sub[k++] = ' ';
            }
            else {
                sub[k++] = s[i];
            }
            i++;
        }
        sub[k]=0;
        //printf("%s\n", sub);
        strcpy(n[t++], sub);
    }
    qsort(n, t, sizeof(char) * 110, cmp);

    for (int i = 0; i < t; i++)
    {
        printf("%s\n", n[i]);
    }
    
    return 0;
}
