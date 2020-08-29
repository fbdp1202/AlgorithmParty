#include <bits/stdc++.h>
using namespace std;

int arr[5];

int main() {
	for (int i=0; i<5; i++)
		scanf("%d", &arr[i]);

  int div = 1;
  while (1) {
		int num = 0;
		for (int i=0; i<5; i++)
			if (div%arr[i]==0)
				num++;
		if (num >= 3) break;
	    div++;
	}
	printf("%d\n", div);
	return 0;
}