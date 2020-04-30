// baekjoon 1149
#include <iostream>
using namespace std;

int main(void)
{
	int N;
	int red, green, blue;
	int result = 0;
	int tmp, tmp2;
	cin >> N;
	if(N == 1){
		cin >> red >> green >> blue;
		tmp = (red < green) ? red : green;
		result += (tmp < blue) ? tmp : blue;
		cout << result;		return 0;
	}
	if(N == 2){
		cin >> red >> green >> blue;
		tmp = (red < green) ? red : green;
		result += (tmp < blue) ? tmp : blue;
		cin >> red >> green >> blue;
		tmp = (red < green) ? red : green;
		result += (tmp < blue) ? tmp : blue;
		cout << result;		return 0;
	}
	int *red_money = new int[N];
	int *green_money = new int[N];
	int *blue_money = new int[N];
	cin >> red >> green >> blue;
	red_money[0] = red;
	green_money[0] = green;
	blue_money[0] = blue;
	for (int i = 1; i < N; ++i)
	{
		cin >> red >> green >> blue;
		if(green_money[i-1] < blue_money[i-1]) 	red_money[i] = red + green_money[i-1];
		else 									red_money[i] = red + blue_money[i-1];
		if(red_money[i-1] < blue_money[i-1]) 	green_money[i] = green + red_money[i-1];
		else 									green_money[i] = green + blue_money[i-1];
		if(green_money[i-1] < red_money[i-1]) 	blue_money[i] = blue + green_money[i-1];
		else 									blue_money[i] = blue + red_money[i-1];
	}
	red = red_money[N-1]; green = green_money[N-1]; blue = blue_money[N-1];
	tmp = (red < green) ? red : green;
	result = (tmp < blue) ? tmp : blue;
	cout << result;		return 0;
}