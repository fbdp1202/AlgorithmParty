// baekjoon 5073 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[3];

void Print(int x) {
	switch(x) {
		case 0: printf("Equilateral\n"); break;
		case 1: printf("Isosceles\n"); break;
		case 2: printf("Scalene\n"); break;
		case 3: printf("Invalid\n"); break;
	}
}

int main()
{
	while (1)
	{
		for (int i=0; i<3; i++)
			scanf("%d", &arr[i]);

		if (arr[0] + arr[1] + arr[2] == 0) break;

		sort(arr, arr+3);

		if (arr[2] >= arr[0] + arr[1]) {
			Print(3);
			continue;
		}
		if (arr[0] == arr[2]) {
			Print(0);
			continue;
		}
		if (arr[0] == arr[1] || arr[1] == arr[2]) {
			Print(1);
			continue;
		}
		Print(2);
	}
	return 0;
}