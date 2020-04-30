// baekjoon 2529 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int k;
bool used[10];
int num_max[10];
int num_min[10];
char num_op[9];
char buf[5];

int minarr(){
	for(int i=0; i<10; i++)
		if(!used[i]) return i;
	return 10;
}

int maxarr(){
	for(int i=9; i>=0; i--)
		if(!used[i]) return i;
	return 0;
}

int main()
{
	int last=0, tmp;
	int op = -1;	 // < : 0, > : 1
	char c;

	scanf("%d", &k);
	for(int i=0; i<k; i++){
		scanf("%s", buf);
		num_op[i] = buf[0];
	}

	// compute max value
	used[9] = true;
	num_max[0] = 9;

	for(int i=0; i<k; i++){
		if(num_op[i] == '<'){
			if(op != 0) { last=i; tmp = num_max[i]+1; }
			int new_tmp = tmp;
			for(int j=i+1; j>= last; j--){
				new_tmp--;
				num_max[j] = new_tmp;
				used[new_tmp] = true;
			}
			op = 0;
		}
		else{
			num_max[i+1] = maxarr();
			used[num_max[i+1]] = true;
			tmp = num_max[i+1];
			op = 1;
		}
	}
	for(int i=0; i<k+1; i++)
		printf("%d", num_max[i]);
	printf("\n");

	// compute min value
	fill(used, used+10, false);
	op = -1;
	used[0] = true;
	num_min[0] = 0;
	
	for(int i=0; i<k; i++){
		if(num_op[i] == '>'){
			if(op != 0) { last=i; tmp = num_min[i]; }
			int new_tmp = tmp;
			for(int j=i+1; j >= last; j--){
				num_min[j] = new_tmp;
				used[new_tmp] = true;
				new_tmp++;
			}
			op = 0;
		}
		else{
			num_min[i+1] = minarr();
			used[num_min[i+1]] = true;
			tmp = num_min[i+1];
			op = 1;
		}
	}
	for(int i=0; i<k+1; i++)
		printf("%d", num_min[i]);
}