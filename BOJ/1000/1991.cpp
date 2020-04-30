// baekjoon 1991 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct node{
	char c;
	struct node *ln, *rn;
}node;

node init_node(char data, node *pl, node *pr) {
	node n;
	n.c = data;
	n.ln = pl;
	n.rn = pr;
	return n;
}


void preorder_traversal(node *root) {
	printf("%c", root->c);
	if (root->ln) preorder_traversal(root->ln);
	if (root->rn) preorder_traversal(root->rn);
}

void inorder_traversal(node *root) {
	if (root->ln != NULL) inorder_traversal(root->ln);
	printf("%c", root->c);
	if (root->rn != NULL) inorder_traversal(root->rn);
}

void postorder_traversal(node *root) {
	if (root->ln != NULL) postorder_traversal(root->ln);
	if (root->rn != NULL) postorder_traversal(root->rn);
	printf("%c", root->c);
}


int main() {
	int N;
	scanf("%d", &N);
	node *root = new node[N];
	char c;
	for (int i=0; i<N; i++) {
		char target;
		node *pl=NULL, *pr=NULL;
		scanf(" %c", &target);
		scanf(" %c", &c);
		if (c != '.') pl = &root[c-'A'];
		scanf(" %c", &c);
		if (c != '.') pr = &root[c-'A'];
		root[target-'A'] = init_node(target, pl, pr);
	}
	preorder_traversal(&root[0]);
	puts("");
	inorder_traversal(&root[0]);
	puts("");
	postorder_traversal(&root[0]);
	puts("");
	return 0;
}