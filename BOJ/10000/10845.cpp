// baekjoon 10845 yechan
#include <iostream>
#include <cstdlib>
using namespace std;

class UnderflowException{};

template<typename T>
class ListNode{
public:
	T value;
	ListNode<T> *next;

	ListNode<T>(): next(nullptr){}
	ListNode<T>(T value1, ListNode<T> *next1): value(value1), next(next1){}
};

template<typename T>
class Queue{
public:
	int size;
	ListNode<T> *head, *tail;

	Queue<T>(): size(0), head(nullptr), tail(nullptr){}

	~Queue<T>(){
		ListNode<T> *t1 = head, *t2;
		while (t1 != nullptr) {
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}

	int getSize(){
		return size;
	}

	int empty(){
		return size == 0;
	}

	void push(T value){
		if (size == 0) head = tail = new ListNode<T>(value, nullptr);
		else {
			tail->next = new ListNode<T>(value, nullptr);
			tail = tail->next;
		}
		size++;
	}

	T front(){
		try{
			if (size == 0) throw UnderflowException();
			return head->value;
		}
		catch (UnderflowException e) {
			return -1;
		}
	}

	T back(){
		try{
			if (size == 0) throw UnderflowException();
			return tail->value;
		}
		catch (UnderflowException e) {
			return -1;
		}
	}

	void pop(){
		try{
			if (size == 0) throw UnderflowException();

			ListNode<T> *temp = head;
			head = head->next;
			delete temp;
			if(head == nullptr) tail = nullptr;
			size--;
		}
		catch (UnderflowException e) {
			return;
		}
	}
};

int main() {
    int N;
    Queue<int> Q;
    cin >> N;
	for (int i=0; i<N; i++) {
		string str;
		cin >> str;
		if (str.compare("push") == 0) {
			int X;
			cin >> X;
			Q.push(X);
		}
		else if (str.compare("pop") == 0) {
			cout << Q.front() << endl;
			Q.pop();
		}
		else if (str.compare("size") == 0) {
			cout << Q.getSize() << endl;
		}
		else if (str.compare("empty") == 0) {
			cout << Q.empty() << endl;
		}
		else if (str.compare("front") == 0) {
			cout << Q.front() << endl;
		}
		else if(str.compare("back") == 0) {
			cout << Q.back() << endl;
		}
	}    
}