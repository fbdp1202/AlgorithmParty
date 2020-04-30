// baekjoon 2839
#include <stdio.h>

int main(void){
    int A, num;
    scanf("%d", &A);
    num = -1;
    for(int i = A/5; i >= 0; i--)
    {
    	for(int j = 0; j*3+i*5 <=A; j++)
    	{
    		if(3*j + i*5 == A){
    			num = i+j;
    			break;
    		}
    	}
    	if(num != -1)
    		break;
    }
    printf("%d", num);
    return 0;
}