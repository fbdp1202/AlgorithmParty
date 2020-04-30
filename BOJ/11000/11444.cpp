// baekjoon 11444 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ll;

ll N;

struct Matrix{
	ll mat[2][2];
	Matrix() {
		mat[0][0] = 0;
		mat[0][1] = 0;
		mat[1][0] = 0;
		mat[1][1] = 0;
	}
};

Matrix matrixMul(Matrix& a, Matrix& b) {
	Matrix c;
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			for (int k=0; k<2; k++)
				c.mat[i][j] += a.mat[i][k]*b.mat[k][j];
	return c;
}

int main() {
	scanf("%lld", &N);
	Matrix a, ret;
	// F_n+2 = F_n+1 + F_n
	// (F_n+1, F_n) = (1, 1; 1, 0)(F_n, F_n-1)
	a.mat[0][0] = a.mat[0][1] = a.mat[1][0] = 1;
	ret.mat[0][0] = ret.mat[1][1] = 1;

	while (N) {
		if (N%2) ret = matrixMul(ret, a);
		N/=2;
		a = matrixMul(a, a);
	}
	printf("%lld\n", ret.mat[1][0]);
	return 0;
}