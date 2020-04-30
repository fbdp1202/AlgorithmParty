// baekjoon 1700 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;

int N, K, seq[MAX_N], ret;
vector<int> plugs;

int main() {
	scanf("%d%d", &N, &K);
	for (int i=0; i<K; i++)
		scanf("%d", &seq[i]);

	for (int i=0; i<K; i++) {
		bool used = false;
		for (int &p: plugs) {
			if (p == seq[i]) {
				used = true;
				break;
			}
		}
		if (used) continue;

		if (plugs.size() < N) {
			plugs.push_back(seq[i]);
			continue;
		}

		int maxSeqIdx = 0;
		int maxPlugIdx = 0;
		for (int j=0; j<plugs.size(); j++) {
			int tmpSeqIdx = 1e9;
			for (int k=i+1; k<K; k++) {
				if (plugs[j] == seq[k]) {
					tmpSeqIdx = k;
					break;
				}
			}
			if (tmpSeqIdx > maxSeqIdx) {
				maxSeqIdx = tmpSeqIdx;
				maxPlugIdx = j;
			}
		}
		// plug out maxPlugIdx
		ret++;
		plugs[maxPlugIdx] = seq[i];
	}
	printf("%d\n", ret);
	return 0;
}