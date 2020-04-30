#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
vector<int> v[51];
vector<int> parent;
queue<int> q;
int N, m, c, cnt;
 
void bfs()
{
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        int size = v[front].size();
        if (size == 0)
            cnt++;
        else
            for (int i = 0; i < size; i++)
                q.push(v[front][i]);
    }
}
 
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> m;
        if (m != -1)
            v[m].push_back(i);
        else
            parent.push_back(i);
    }
    cin >> c;
    
    for (vector<int>::iterator iter = parent.begin(); iter != parent.end(); iter++) {
        if (*iter == c) {
            parent.erase(iter);
            break;
        }
    }
 
    for (int i = 0; i < N; i++) {
        for (vector<int>::iterator iter = v[i].begin(); iter != v[i].end(); iter++)
            if (*iter == c) {
                v[i].erase(iter);
                break;
            }
                
    }
    int size = parent.size();
    for (int i = 0; i < size; i++) {
        q.push(parent[i]);
        bfs();
    }
    cout << cnt;
    return 0;
}
