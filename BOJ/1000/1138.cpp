// baekjoon 1138 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int len[11];
int arr[11];

void arrinsert(int num, int pos){
	for(int i=10; i > pos; i--)
		arr[i] = arr[i-1];
	arr[pos] = num;
}

int findpos(int num, int cnt){
	int tmp=0;
	for(int i=1; i<11; i++){
		if(tmp==cnt) return i;
		if(num<arr[i]) tmp++;
	}
}

int main()
{
	scanf("%d", &N);
	for(int i=1; i<N+1; i++)
		scanf("%d", &len[i]);
	for(int i=N; i>=1; i--)
		arrinsert(i, findpos(i, len[i]));
	for(int i=1; i<N+1; i++)
		printf("%d ", arr[i]);
}