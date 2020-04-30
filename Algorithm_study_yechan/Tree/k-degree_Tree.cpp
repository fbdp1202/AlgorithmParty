#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Tree{
public:
	int N; // 정점의 개수
	vector<int> parent; // 부모 노드
	vector<int> lc, rc; // 왼쪽 자식, 오른쪽 자식 노드

	// 생성자
	Tree(): N(0){}
	Tree(int n): N(n){
		parent.resize(N, -1);
		lc.resize(N, -1);
		rc.resize(N, -1);
	}

	void setChildren(int p, int l, int r){
		if(l != -1) parent[l] = p;
		if(r != -1) parent[r] = p;
		lc[p] = l;
		rc[p] = r;
	}

	void preorder(int root){
		cout << root << ' ';
		if(lc[root] != -1) preorder(lc[root]);
		if(rc[root] != -1) preorder(rc[root]);
	}

	void inorder(int root){
		if(lc[root] != -1) inorder(lc[root]);
		cout << root << ' ';
		if(rc[root] != -1) inorder(rc[root]);
	}

	void postorder(int root){
		if(lc[root] != -1) postorder(lc[root]);
		if(rc[root] != -1) postorder(rc[root]);
		cout << root << ' ';
	}

	void levelorder(int root){
		queue<int> Q;
		Q.push(root);
		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			cout << curr << ' ';
			if(lc[curr] != -1) Q.push(lc[curr]);
			if(rc[curr] != -1) Q.push(rc[curr]);
		}
	}

	int getHeight(int root){
		int result = 1;
		for(int c: children[root])
			result = max(result, getHeight(c) + 1);
		return result;
	}
};

int main(){
    Tree T(10);
    T.setChildren(0, 1, 2);
    T.setChildren(1, 3, 4);
    T.setChildren(2, -1, 5);
    T.setChildren(3, 6, 7);
    T.setChildren(5, 8, 9);
    
    cout << "Preorder   : ";
    T.preorder(0);
    cout << endl << "Inorder    : ";
    T.inorder(0);
    cout << endl << "Postorder  : ";
    T.postorder(0);
    cout << endl << "Level-order: ";
    T.levelorder(0);
    cout << endl;
}