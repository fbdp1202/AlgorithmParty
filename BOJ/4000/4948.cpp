// baekjoon 4948 yechan
#include <iostream>
#include <algorithm>
using namespace std;

#define N_MAX 123456

int main()
{
	int tmp, count;
	bool *isPrime = new bool[N_MAX*2 + 1]; 
	fill(isPrime, isPrime+N_MAX*2 + 1, 1);	// Set 1

	isPrime[0] = 0; isPrime[1] = 0; 		// initial
	for(int i=2; i < N_MAX*2 + 1; i++) 		// find prime number
		if(isPrime[i])
			for(int j = i*2; j < N_MAX*2+1; j+= i)
				isPrime[j] = 0;				// remove non prime number

	cin >> tmp;
	while(tmp){ 							// if tmp is non zero
		count = 0;
		for(int i = tmp + 1; i <= tmp*2 ; i++)  // find n+1 ~ 2n prime number
			if(isPrime[i]) count++;
		cout << count;
		cin >> tmp;
	}
}