#include <cstdio>
#include <algorithm>
using namespace std;
 
int main()
{
  int A, B, C;
  scanf("%d%d%d", &A, &B, &C);
  printf("%d\n", max(0, C-(A-B)));
  return 0;
}