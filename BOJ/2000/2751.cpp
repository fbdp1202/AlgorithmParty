// baekjoon 2751 yechan
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int N, tmp;

int main()
{
	priority_queue<int, vector<int>, greater<int>> PQ;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &tmp), PQ.push(tmp);

	while(!PQ.empty()){
		printf("%d\n", PQ.top());
		PQ.pop();
	}
	return 0;
}

/*
// baekjoon 2751 rithm
#include <stdio.h>

inline int readChar();
template <class T = int>
inline T readInt();
template <class T>
inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char *s);

static const int buf_size = 1 << 21;

inline int getChar() {
  static char buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len) pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len) return -1;
  return buf[pos++];
}

inline int readChar() {
  int c = getChar();
  while (c <= 32) c = getChar();
  return c;
}

template <class T>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-') s = -1, c = getChar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt(T x, char end) {
  if (x < 0) writeChar('-'), x = -x;

  char s[24];
  int n = 0;
  while (x || !n) s[n++] = '0' + x % 10, x /= 10;
  while (n--) writeChar(s[n]);
  if (end) writeChar(end);
}

inline void writeWord(const char *s) {
  while (*s) writeChar(*s++);
}

struct Flusher {
  ~Flusher() {
    if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
  }
} flusher;

int main() {
  int n, num, arr[2000001] = {0};
  
  n = readInt();
  for (int i = 0; i < n; i++) {
    num = readInt();
    arr[num + 1000000] = 1;
  }

  for (int i = 0; i < 2000001; i++) {
    if (arr[i]) {
      writeInt(i - 1000000, '\n');
    }
  }
    
  return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

namespace fio {
    const int BSIZE = 524288;
    char buffer[BSIZE+1];
    int p = BSIZE;
    inline char readChar() {
        if(p == BSIZE) {
            buffer[fread(buffer, 1, BSIZE, stdin)] = '\n';
            p = 0;
        }
        return buffer[p++];
    }
    int readInt() {
        char c = readChar();
        while ((c < '0' || c > '9') && c != '-') {
            c = readChar();
        }
        int ret = 0; bool neg = c == '-';
        if (neg) c = readChar();
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + c - '0';
            c = readChar();
        }
        return neg ? -ret : ret;
    }
}
bool s[2000005];
int main()
{
    int n = fio::readInt();
    for(int i=0;i<n;i++)
    {
        int x = fio::readInt();
        s[x+1000000] = true;
    }
    for(int i=0;i<=2000000;i++)
        if(s[i]) printf("%d\n",i-1000000);
}
*/