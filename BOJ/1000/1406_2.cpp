// baekjoon 1406_2 yechan
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	ListNode():ListNode('\0',nullptr,nullptr){}
	ListNode(char d, ListNode *p, ListNode *n):data(d),prev(p),next(n){}
	char data;
	ListNode *prev, *next;
};

struct List {
public:
	List():size(0){
		front = rear = current = new ListNode('\0', nullptr, nullptr);
	}

	void moveLeft() {
		if (current != rear) current = current->prev;
	}

	void moveRight() {
		if (current != front) current = current->next;
	}

	void erase() {
		if (current == rear) return;
		ListNode *temp = current->prev;
		if (current->prev == rear) {
			rear = current;
			current->prev = nullptr;
		}
		else {
			current->prev->prev->next = current;
			current->prev = current->prev->prev;
		}
		delete temp;
		size--;
	}

	void insert(char ch) {
		ListNode *temp = new ListNode(ch, current->prev, current);
		if (current == rear) rear = temp;
		else current->prev->next = temp;
		current->prev = temp;
		size++;
	}

	int getSize() {
		return size;
	}

	void print() {
		ListNode *temp = rear;
		while (temp != front) {
			putchar(temp->data);
			temp = temp->next;
		}
		putchar('\n');
	}

private:
	int size;
	ListNode *front, *rear, *current;
};

int main() {
	List text;
	int N;
	char opcode, ch;
	while ( (ch=getchar()) != '\n')
		text.insert(ch);
	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		getchar();
		opcode = getchar();
		switch (opcode) {
		case 'L':
			text.moveLeft();
			break;
		case 'D':
			text.moveRight();
			break;
		case 'B':
			text.erase();
			break;
		case 'P':
			getchar();
			ch = getchar();
			text.insert(ch);
		}
	}
	text.print();
	return 0;
}