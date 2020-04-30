#include<stdio.h>
int C,K,R,p=1;int main(){scanf("%d%d",&C,&K);while(K--)R=C%10,C/=10,p*=10;if(R>=5)C++;return!printf("%d", C*p);}