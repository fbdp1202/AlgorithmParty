/*
대경권 예선 1번
문제설명
정말 1번 다운 단순한 구현문제
예제를 보면 문제 이해가 쉽다.
다음과 같은 입력이 주어지면 아래와 순서로 압축된다.

ex)
1 2 2 3 4
1 2 1 1
1 1 2
2 1
1 1
2
1

총 6번에 단계에 거쳐서 1의 값을 가지게 된다.
눈치 채신 분은 눈치 채시겠지만, 앞에서부터 단순하게
1 2 2 3 4
-> 1이 '1'개, 2개 '2'개, 3이 '1'개, 4가 '1'개로
결과 = 1 2 1 1
이러한 형태로 1이 될때까지 걸리는 시간를 출력하면 된다.

ex)
input:
1 2 2 3 4

output:
6

input:
1

output:
0

알고리즘:
알고리즘이라고 할꺼 없다 그냥 구현하자...
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_N = 1001;

int N;
vector<int> seqn;

int main(void) {
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int a;
        scanf("%d", &a);
        seqn.push_back(a);
    }

    int ans = 0;
    while(1){
        int cnt = 0;
        int cur = seqn[0];
        int size = seqn.size();

        if(size == 1 && cur == 1) break;
        vector<int> temp;

        for(int i = 0; i < size; i++){
            if(cur == seqn[i]) cnt++;
            else{
                cur = seqn[i];
                temp.push_back(cnt);
                cnt = 1;
            }
        }
        if(cur == seqn[size-1]){
            temp.push_back(cnt);
        }

        
        seqn.clear();
        for(int i = 0; i < temp.size(); i++){
            seqn.push_back(temp[i]);
        }

        ans++;
    }
    printf("%d", ans);
    return 0;
}