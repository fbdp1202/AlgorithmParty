#include <cstdio>
#include <algorithm>
using namespace std;

int A, arr[4];

int main() {
	scanf("%d", &A);
	arr[3] = A/1000;
	arr[2] = (A/100)%10;
	arr[1] = (A/10)%10;
	arr[0] = A%10;

	int cnt = arr[3] + arr[2] + arr[1] + arr[0];
	while (cnt % 4) {
		arr[0]++;
		if (arr[0] == 10) {
			arr[0] = 0;
			arr[1]++;
			if (arr[1] == 10) {
				arr[1] = 0;
				arr[2]++;
				if (arr[2] == 10) {
					arr[2] = 0;
					arr[3]++;
				}
			}
		}
		cnt = arr[3] + arr[2] + arr[1] + arr[0];
	}
	int value = 0;
	for (int i=3; i>=0; i--) {
		value *= 10;
		value += arr[i];
	}
	printf("%d\n", value);
	return 0;
}