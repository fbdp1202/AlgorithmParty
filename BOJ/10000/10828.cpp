// baekjoon 10828 yechan
#include <iostream>
#include <cstdlib>
#include <string>
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
class Stack{
public:
	int size;
	ListNode<T> *tail;

	Stack<T>(): size(0), tail(nullptr){}

	~Stack<T>(){
		ListNode<T> *t1 = tail, *t2;
		while(t1 != nullptr){
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}

	void push(T value){
		tail = new ListNode<T>(value, tail);
		size++;
	}

	T top(){
		try{
			if(size == 0) throw UnderflowException();

			return tail->value;
		}
		catch(UnderflowException e){
			return -1;
		}
	}

	void pop(){
		try{
			if(size == 0) throw UnderflowException();

			ListNode<T> *temp = tail->next;
			delete tail;
			tail = temp;
			size--;
		}
		catch(UnderflowException e){
			return;
		}
	}
	T getSize(){
		return size;
	}
};

int main(){
    Stack<int> S;
    int N;
    cin >> N;
    while (N--) {
	    string buf;
    	cin >> buf;
    	if(!buf.compare("push")){
    		int x;
    		cin >> x;
    		S.push(x);
    	}
    	if(!buf.compare("top")){
    		cout << S.top() << endl;
    	}
    	if(!buf.compare("pop")){
    		cout << S.top() << endl;
			S.pop();
    	}
    	if(!buf.compare("size")){
    		cout << S.getSize() << endl;
    	}
    	if(!buf.compare("empty")){
    		cout << ((S.getSize() == 0) ? 1 : 0)  << endl;
    	}
    }
}