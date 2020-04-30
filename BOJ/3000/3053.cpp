// baekjoon 3053 yechan
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(void)
{
	double R, cycle_size;
	cin >> R;
	cycle_size = R*R*M_PI;
	cout << setprecision(6) << fixed;
	cout << cycle_size << endl;
	cycle_size = 2.f*R*R;
	cout << cycle_size;
}