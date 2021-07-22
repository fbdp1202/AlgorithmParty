#include <bits/stdc++.h>
using namespace std;

int T, N, d;
const int MAX_N=50001;

char str[MAX_N];
int A[MAX_N];
char B[MAX_N];

int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

void fillZeros() {
    for (int i=0; i<N; i++) {
        if (B[i] == '0') {
            int up = i - d;
            int down = i + d;
            if (up >= 0 && up < N)
                A[up] = 0;
            if (down >= 0 && down < N)
                A[down] = 0;
        }
    }
}

void fillOnes() {
    for (int i=0; i<N; i++) {
        if (B[i] == '1') {
            int up = i - d;
            int down = i + d;

            bool flag = false;
            bool upOn = false;
            bool downOn = false;

            if (up >= 0 && up < N) {
                if (A[up] == 1) flag = true;
                if (A[up] == -1) upOn = true;
            }
            if (down >= 0 && down < N) {
                if (A[down] == 1) flag = true;
                if (A[down] == -1) downOn = true;
            }
            if (flag) continue;

            if (downOn) {
                A[down] = 1;
                flag = true;
            }
            if (flag) continue;

            if (upOn) {
                A[up] = 1;
                flag = true;
            }
        }
    }
}

void PrintSol() {
    for (int i=0; i<N; i++) {
        if (A[i] == -1) A[i] = 0;
        str[i] = A[i] + '0';
    }
    str[N]='\0';
    printf("%s\n", str);
}

int main () {
    setbuf(stdout, NULL);

    T = read_int();
    for (int t=1; t<=T; t++) {
        printf("Case #%d\n", t);
        fill(A, A+MAX_N, -1);
        N = read_int();
        d = read_int();
        scanf(" %s", B);
        fillZeros();
        fillOnes();
        PrintSol();
    }
    return 0;
}