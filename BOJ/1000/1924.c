// baekjoon 1924
#include <stdio.h>

int cal_day(int month, int day);
void print_day(int day);

int main(void) {
	int month, day;
	scanf("%d %d", &month, &day);
	print_day(cal_day(month, day));
	return 0;
}

int cal_day(int month, int day) {
	int dday = 0;
	for (int i = 1; i < month; i++) {
		switch (i) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12: dday += 31; break;
			case 4:
			case 6:
			case 9:
			case 11: dday += 30; break;
			case 2:  dday += 28;
		}
	}
	dday += day;
	return dday % 7;
}

void print_day(int day) {
	switch (day)
	{
	case 0: printf("SUN"); break;
	case 1: printf("MON"); break;
	case 2: printf("TUE"); break;
	case 3: printf("WED"); break;
	case 4: printf("THU"); break;
	case 5: printf("FRI"); break;
	case 6: printf("SAT"); break;
	}
}