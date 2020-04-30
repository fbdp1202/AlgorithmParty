// baekjoon 12791 yechan
#include <cstdio>
using namespace std;

int T, cnt, S, E;

int year[25] = {1967, 1969, 1970, 1971, 1972, 1973, 1973, 1974, 1975, 1976, 1977, 1977, 1979, 1980, 1983, 1984, 1987, 1993, 1995, 1997, 1999, 2002, 2003, 2013, 2016};
char title[25][100] = {
"DavidBowie",
"SpaceOddity",
"TheManWhoSoldTheWorld",
"HunkyDory",
"TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars",
"AladdinSane",
"PinUps",
"DiamondDogs",
"YoungAmericans",
"StationToStation",
"Low",
"Heroes",
"Lodger",
"ScaryMonstersAndSuperCreeps",
"LetsDance",
"Tonight",
"NeverLetMeDown",
"BlackTieWhiteNoise",
"1.Outside",
"Earthling",
"Hours",
"Heathen",
"Reality",
"TheNextDay",
"BlackStar"
};

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &S, &E);
		cnt = 0;
		for (int i=0; i<25; i++)
			if (S <= year[i] && year[i] <= E) cnt++;
		printf("%d\n", cnt);
		for (int i=0; i<25; i++)
			if (S <= year[i] && year[i] <= E)
				printf("%d %s\n", year[i], title[i]);
	}
	return 0;
}