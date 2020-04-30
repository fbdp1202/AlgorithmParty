#include <cstdio>

using namespace std;

int sum(int L, int R, int nodeNum, int nodeL, int nodeR){
	if(R < nodeL || nodeR < L) return 0;
	if(L <= nodeL && nodeR <= R) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
}

void update(int i, int val){
	i += size;
	arr[i] = val;
	while(i > 1){
		i /= 2;
		arr[i] = arr[i*2] + arr[i*2+1];
	}
}