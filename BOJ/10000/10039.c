// baekjoon 10039
#include <stdio.h>
int main(void){
    int total = 0;
    for(int i =0; i < 5; i++){
        int ret;
        scanf("%d", &ret);
        if(ret < 40)
            total += 40;
        else
            total += ret;
    }
    total /= 5;
    printf("%d", total);
    return 0;
}