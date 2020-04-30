// baekjoon 1786 reference
#include <stdio.h>
#include <iostream>
#define mv 1000002
 
char t[mv], p[mv];
int f[mv], l, m, q[mv], qi;
 
int strlen(char *s) {
    int i;
    for (i = 0; s[i]; i++);
    return i;
}
 
int main() {
    fgets(t, mv, stdin);
    fgets(p, mv, stdin);
 
    l = strlen(t); m = strlen(p);
    if (t[l - 1] == '\n') t[--l] = 0;
    if (p[m - 1] == '\n') p[--m] = 0;
 
    for (int i = 1, j = 0; i < m; i++) {
        while (j && p[i] != p[j]) j = f[j - 1];
        if (p[i] == p[j]) f[i] = ++j;
    }
 
    for (int i = 0, j = 0; i < l; i++) {
        while (j && t[i] != p[j]) 
            j = f[j - 1];
        if (t[i] == p[j]) {
            if (j == m - 1) {
                q[qi++] = i - m + 2;
                j = f[j];
            }
            else j++;
        }
    }
    printf("%d\n", qi);
    for (int i = 0; i < qi; i++) printf("%d\n", q[i]);
    return 0;
}
