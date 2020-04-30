#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Tree{
public:
	int N; // 정점의 개수
	vector<int> parent; // 부모 노드
	vector<vector<int>> children; // 자식 노드 리스트

	// 생성자
	Tree(): N(0){}
	Tree(int n): N(n){
		parent.resize(N, -1);
		children.resize(N);
	}

	// 각 정점마다 부모, 자식들을 보여주는 함수
	void print(){
		for(int i=0; i<N; i++){
			cout << "Node " << i << ": parent(";
			if(parent[i] != -1) cout << parent[i];
			else cout << "-";
			cout << "), children(";
			for(int j=0; j<children[i].size(); j++){
				cout << children[i][j];
				if(j < children[i].size()-1) cout << ", ";
			}
			cout << ")" << endl;
		}
	}
};

class Graph{
public:
	int N; // 정점의 개수
	vector<vector<int>> adj; // 인접 리스트

	// 생성자
	Graph(): N(0){}
	Graph(int n): N(n){ adj.resize(N); }

	// 간선 추가 함수
	void addEdge(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// 모든 리스트의 인접한 정점 번호 정렬
	void sortList(){
		for(int i=0; i<N; i++)
			sort(adj[i].begin(), adj[i].end());
	}

	// BFS로 트리 만들기(그래프는 완전 그래프라 가정)
	Tree makeTree(int root){
		Tree T(N);
		vector<bool> visited(N, false); // 방문 여부를 저장하는 배열
		queue<int> Q;

		visited[root] = true;
		Q.push(root);
		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			for(int next: adj[curr]){
				if(!visited[next]){
					visited[next] = true;
					Q.push(next);
					T.parent[next] = curr;
					T.children[curr].push_back(next);
				}
			}
		}
		return T;
	}
};

int main(){
    Graph G(9);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 5);
    G.addEdge(3, 4);
    G.addEdge(4, 5);
    G.addEdge(2, 6);
    G.addEdge(2, 8);
    G.addEdge(6, 7);
    G.addEdge(6, 8);
    G.sortList();
    Tree T = G.makeTree(0);
    T.print();
}