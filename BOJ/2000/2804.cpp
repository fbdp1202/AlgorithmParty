// baekjoon 2804 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char A[31], B[31], data[31][31];

int x, y;

bool findStart() {
	for (x=0; A[x]; x++)
		for (y=0; B[y]; y++)
			if (A[x] == B[y]) return true;

	return false;
}

int main() {
	scanf("%s %s", A, B);
	findStart();
	for (int i=0; A[i]; i++) {
		for (int j=0; B[j]; j++) {
			data[j][i] = '.';
		}
	}

	for (int i=0; A[i]; i++) {
		data[y][i] = A[i];
	}

	for (int j=0; B[j]; j++) {
		data[j][x] = B[j];
	}

	for (int j=0; B[j]; j++) {
		printf("%s\n", data[j]);
	}

	return 0;
}