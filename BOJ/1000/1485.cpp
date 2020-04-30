// baekjoon 1485 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define SQ(x) (x)*(x)

typedef struct _TAG_POSITION{
	int x, y;
}__POS;

typedef struct _TAG_RECT
{
	__POS point[4];
}__RECT;

int T, lineDist[3];
__RECT rect;

inline int getLineDist(__POS p1, __POS p2)
{
	return SQ(p1.x-p2.x)+SQ(p1.y-p2.y);
}

int main()
{
	scanf("%d", &T);
	for ( int i=0; i<T; i++ ) {
		int max_dist = 0, max_idx = 0, other_dist = 0, isSquare = 1;

		for ( int j=0; j<4; j++ )
			scanf("%d %d", &rect.point[j].x, &rect.point[j].y);

		for ( int j=0; j<3; j++ ) {
			lineDist[j] = getLineDist(rect.point[0], rect.point[j+1]); 

			if ( max_dist < lineDist[j])
				max_dist = lineDist[j], max_idx = j;
			else
				other_dist = lineDist[j];
		}
		if( !other_dist || ( other_dist*2 != max_dist ) )
			isSquare = 0;

		for ( int j=0; j<3; j++ ) {
			if( j != max_idx ) {
				if( other_dist != lineDist[j] )
					isSquare = 0;

				if( other_dist != 
					getLineDist(rect.point[max_idx+1], rect.point[j+1]) )
					isSquare = 0;
			}
		}
		if ( isSquare ) 	printf("1\n");
		else 				printf("0\n");
	}
	return 0;
}