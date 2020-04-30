// baekjoon 2290 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int s;
char n[11];
bool num[10][5][3]={
	{ // 0
		{false, true, false},
		{true, false, true},
		{false, false, false},
		{true, false, true},
		{false, true, false},
	},
	{ // 1
		{false, false, false},
		{false, false, true},
		{false, false, false},
		{false, false, true},
		{false, false, false},
	},
	{ // 2
		{false, true, false},
		{false, false, true},
		{false, true, false},
		{true, false, false},
		{false, true, false},
	},
	{ // 3
		{false, true, false},
		{false, false, true},
		{false, true, false},
		{false, false, true},
		{false, true, false},
	},
	{ // 4
		{false, false, false},
		{true, false, true},
		{false, true, false},
		{false, false, true},
		{false, false, false},
	},
	{ // 5
		{false, true, false},
		{true, false, false},
		{false, true, false},
		{false, false, true},
		{false, true, false},
	},
	{ // 6
		{false, true, false},
		{true, false, false},
		{false, true, false},
		{true, false, true},
		{false, true, false},
	},
	{ // 7
		{false, true, false},
		{false, false, true},
		{false, false, false},
		{false, false, true},
		{false, false, false},
	},
	{ // 8
		{false, true, false},
		{true, false, true},
		{false, true, false},
		{true, false, true},
		{false, true, false},
	},
	{ // 9
		{false, true, false},
		{true, false, true},
		{false, true, false},
		{false, false, true},
		{false, true, false},
	}
}

int main() {
	scanf("%d%s", &s, n);
	for (int i=0; i<5; i++) {
		if 
	}
	return 0;
}