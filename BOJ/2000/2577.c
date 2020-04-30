// baekjoon 2577
#include <stdio.h>

int main(void)
{
    int A,B,C;
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    int value = A*B*C;
    int state[10] = {0,};
    while(value > 9){
        state[value%10]++; 
        value /= 10;
    }
    state[value]++;
    for(int i=0; i<10; i++)
        printf("%d\n",state[i]);
    return 0;
}