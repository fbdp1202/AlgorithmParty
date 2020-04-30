#include <cstdio>
using namespace std;
const int MAX_N = 600001;

class listNode{
public:
	listNode():data('\0'),prev(nullptr),next(nullptr){};
	listNode(char d, listNode *p, listNode *n):data(d),prev(p),next(n){};
	char data;
	listNode *prev, *next;
};

class list{
public:
	list():size(0) {
		front = rear = current = new listNode('\0', nullptr, nullptr);
	};

	void moveLeft() {
		if (current != rear) current = current->prev;
	}

	void moveRight() {
		if (current != front) current = current->next;
	}

	void erase() {
		if (current == rear) return;
		listNode *temp = current->prev;
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
		if (size == MAX_N) return;
		listNode *temp = new listNode(ch, current->prev, current);
		if (current == rear) rear = temp;
		else current->prev->next = temp;
		current->prev = temp;
		size++;
	}

	int getSize() {
		return size;
	}

	void print() {
		listNode *temp = rear;
		while (temp != front) {
			putchar(temp->data);
			temp = temp->next;
		}
		putchar('\n');
	}
private:
	int size;
	listNode *front, *rear, *current;
};

int main() {
	list text;
	int N;
	char opcode, ch;
	while ( (ch=getchar()) != '\n')
		text.insert(ch);
	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		getchar();
		opcode = getchar();
		switch(opcode) {
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
}