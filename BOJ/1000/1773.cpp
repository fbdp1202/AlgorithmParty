#include <stdio.h>
int N,C,cnt,x,i; bool v[2000001];
int main(){scanf("%d%d",&N,&C);while(N--){scanf("%d", &x);if(v[x])continue;for(i=x;i<=C;i+=x) v[i]=true;}for(i=1;i<=C;i++)cnt+=v[i];return!printf("%d\n",cnt);}