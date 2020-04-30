#include <iostream>
#include <cstdlib>
using namespace std;
 
class UnderflowException{};
 
template<typename T>
class ListNode{
public:
    T value;
    ListNode<T> *next; // 마지막 노드면 nullptr
 
    // 생성자
    ListNode<T>(): next(nullptr){}
    ListNode<T>(T value1, ListNode<T> *next1): value(value1), next(next1){}
};
 
template<typename T>
class Stack{
public:
    int size;
    ListNode<T> *tail;
 
    // 생성자
    Stack<T>(): size(0), tail(nullptr){}
 
    // 소멸자
    ~Stack<T>(){
        ListNode<T> *t1 = tail, *t2;
        while(t1 != nullptr){
            t2 = t1->next;
            delete t1;
            t1 = t2;
        }
    }
 
    // 멤버 함수
    void push(T value){ // 맨 위에 새 원소 삽입
        tail = new ListNode<T>(value, tail);
        size++;
    }
 
    T top(){ // 맨 위의 원소 반환
        try{
            // 예외 처리: 스택이 비어 있음
            if(size == 0) throw UnderflowException();
 
            return tail->value;
        }
        catch(UnderflowException e){
            cerr << "스택이 비어 있는데 top 연산을 시도했습니다." << endl;
            exit(1);
        }
    }
 
    void pop(){ // 맨 위의 원소 제거
        try{
            // 예외 처리: 스택이 비어 있음
            if(size == 0) throw UnderflowException();
 
            ListNode<T> *temp = tail->next;
            delete tail;
            tail = temp;
            size--;
        }
        catch(UnderflowException e){
            cerr << "스택이 비어 있는데 pop 연산을 시도했습니다." << endl;
            exit(2);
        }
    }
};
 
template<typename T>
ostream& operator <<(ostream &out, const Stack<T> &LL){ // 원소들을 한 줄에 차례대로 출력
    ListNode<T> *temp = LL.tail;
    out << "top [";
    for(int i=0; i<LL.size; i++){
        out << temp->value;
        temp = temp->next;
        if(i < LL.size-1) out << ", ";
    }
    out << "] bottom";
    return out;
}
 
int main(){
    Stack<int> S;
    S.push(0); cout << S << endl;
    S.push(1); cout << S << endl;
    S.push(2); cout << S << endl;
    S.push(3); cout << S << endl;
    S.pop(); cout << S << endl;
    S.push(4); cout << S << endl;
    S.pop(); cout << S << endl;
    S.pop(); cout << S << endl;
    S.push(5); cout << S << endl;
    S.pop(); cout << S << endl;
    S.pop(); cout << S << endl;
    S.pop(); cout << S << endl;
}
