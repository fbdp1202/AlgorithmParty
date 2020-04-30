// baekjoon 2816 yechan
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int kbs1 = 0;
    int kbs2 = 0;
    int N;
    cin >> N;
    string str;
    for (int i=0; i<N; i++) {
        cin >> str;
        if (str == "KBS1") kbs1=i;
        if (str == "KBS2") kbs2=i;
    }

    int start = 0;
    int i=0;
    for (; i!=kbs1; i++) cout << "1";
    for (; i!=0; i--) cout << "4";
    if (kbs1 > kbs2) kbs2++;
    for (; i!= kbs2; i++) cout << "1";
    for (; i!=1; i--) cout << "4";

    return 0;
}