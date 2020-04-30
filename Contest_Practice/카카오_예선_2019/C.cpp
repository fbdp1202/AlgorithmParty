#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int,int> P;

int N, M;
vector<P> pKey[4];
vector<vector<int>> plock;
int cnt;

bool BFS(int d) {
    for (int x = -20; x <= 20; x++) {
        for (int y = -20; y <= 20; y++) {
            bool check = true;
            int num = 0;
            for (int i = 0; i < pKey[d].size(); i++) {
                int nx = pKey[d][i].first + x;
                int ny = pKey[d][i].second + y;
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (!plock[nx][ny]) num++;
                else {
                    check=false;
                    break;
                }
            }
            if (check && (num == cnt)) {
                return true;
            }
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    M = key.size();
    N = lock.size();
    plock = lock;
    for (int i=0; i<M; i++)
        for (int j=0; j<M; j++) {
            if (key[i][j]) {
                int nx = i*10 - M*5 + 5, ny = j*10 - M*5 + 5;
                int tmp;
                for (int d=0; d<4; d++) {
                    pKey[d].push_back(P((nx + M*5 - 5)/10, (ny + M*5 - 5)/10));
                    tmp = nx;
                    nx = ny;
                    ny = -tmp;
                }
            }
        }



    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cnt += !lock[i][j];
        }
    }
    
    for (int d=0; d<4; d++) {
        answer |= BFS(d);
    }

    return answer;
}


int main()
{
	scanf("%d", &M);
	vector<vector<int>> key(M);
	for (int i=0; i<M; i++)
		for (int j=0; j<M; j++) {
			int x;
			scanf("%d", &x);
			key[i].push_back(x);
		}

	scanf("%d", &N);
	vector<vector<int>> lock(N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++) {
			int x;
			scanf("%d", &x);
			lock[i].push_back(x);
		}

	puts(solution(key, lock) ? "true" : "false");
	return 0;
}
