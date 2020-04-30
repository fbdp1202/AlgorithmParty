/*
기본 함수 구조 및 매개변수
void * memset (void * ptr, int value, size_t num);
 */
#include <string.h>
#include <stdio.h>

int main() {
	char a[20];

	// 1바이트마다 모드 65로 초기화
	memset(a, 65, sizeof(a));

	for (int i=0; i< (sizeof(a)/sizeof(char)); i++) {
		printf("%c\n", a[i]);
	}
	
	return 0;
}