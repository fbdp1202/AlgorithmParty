#include <iostream>
#include <algorithm>
using namespace std;
void Print(int *arr) {
	cout << "arr[i] : ";
	for (int i=0; i<10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(void) {
	int arr[10] = {3, 7, 2, 4, 1, 0, 9, 8, 5, 6};
	Print(arr); // 정렬 전 출력
	sort(arr, arr+10); //[arr, arr+10) default(오름차순)으로 정렬
	Print(arr); // 정렬 후 출력

	return 0;
}
// > output
// arr[i] : 3 7 2 4 1 0 9 8 5 6
// arr[i] : 0 1 2 3 4 5 6 7 8 9
// Program ended with exit code : 0