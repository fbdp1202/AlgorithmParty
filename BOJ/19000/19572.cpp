#include <bits/stdc++.h>
using namespace std;

float d1,d2,d3;
float a, b, c;

int main() {
    scanf("%f%f%f", &d1, &d2, &d3);
    a = (d1+d2-d3)/2;
    b = (d1-d2+d3)/2;
    c = (-d1+d2+d3)/2;
    if (a >= 0.05 && b >= 0.05 && c >= 0.05) printf("1\n%.1f %.1f %.1f\n", a, b, c);
    else puts("-1");
    return 0;
}