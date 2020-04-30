// baekjoon 10830 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=5;
const int DIV_NUM=1000;

struct Matrix{
	int data[5][5];
	Matrix() {
		for (int i=0; i<5; i++)
			for (int j=0; j<5; j++) 
				data[i][j] = 0;
	}
};

Matrix Mul(Matrix a, Matrix b, int s) {
	Matrix c;
	for (int i=0; i<s; i++)
		for (int j=0; j<s; j++)
			for (int k=0; k<s; k++)
				c.data[i][j] = (c.data[i][j] + a.data[i][k] * b.data[k][j]) % DIV_NUM;

	return c;
}

int main()
{
	int N;
	long long B;
	scanf("%d%lld", &N, &B);
	Matrix a;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d", &a.data[i][j]);

	Matrix ret;
	for (int i=0; i<N; i++)
		ret.data[i][i]=1;

	while (B) {
		if (B & 1) ret = Mul(ret, a, N);
		a = Mul(a, a, N);
		B /= 2;
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++)
			printf("%d ", ret.data[i][j]);
		puts("");
	}

	return 0;
}