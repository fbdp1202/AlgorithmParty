#include <iostream>
#include <cstdlib>
using namespace std;
 
class InvalidIndexException{};
 
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
class LinkedList{
public:
    int size;
    ListNode<T> *head;
 
    // 생성자
    LinkedList<T>(): size(0), head(nullptr){}
 
    // 소멸자
    ~LinkedList<T>(){
        ListNode<T> *t1 = head, *t2;
        while(t1 != nullptr){
            t2 = t1->next;
            delete t1;
            t1 = t2;
        }
    }
 
    // 멤버 함수
    void insert(int k, T value){ // k번째 원소 앞에 새 원소 삽입
        try{
            // 예외 처리: 잘못된 인덱스
            if(k < 0 || k > size) throw InvalidIndexException();
 
            if(k == 0){ // 처음에 삽입
                head = new ListNode<T>(value, head);
            }
            else{ // k번째 원소 앞에 삽입
                ListNode<T> *dest = head;
                for(int i=0; i<k-1; i++) dest = dest->next;
                dest->next = new ListNode<T>(value, dest->next);
            }
            size++;
        }
        catch(InvalidIndexException e){
            cerr << "잘못된 인덱스입니다." << endl;
            exit(1);
        }
    }
 
    void erase(int k){ // k번째 원소를 제거
        try{
            // 예외 처리: 잘못된 인덱스
            if(k < 0 || k >= size) throw InvalidIndexException();
 
            if(k == 0){ // head를 삭제
                ListNode<T> *temp = head->next;
                delete head;
                head = temp;
            }
            else{ // k번째 원소 삭제
                ListNode<T> *dest = head, *temp;
                for(int i=0; i<k-1; i++) dest = dest->next;
                temp = dest->next->next;
                delete dest->next;
                dest->next = temp;
            }
            size--;
        }
        catch(InvalidIndexException e){
            cerr << "잘못된 인덱스입니다." << endl;
            exit(2);
        }
    }
 
    int search(T value){ // 값을 찾아 첫번째 인덱스 리턴, 없으면 -1 리턴
        ListNode<T> *temp = head;
        for(int i=0; i<size; i++){
            if(temp->value == value) return i;
            temp = temp->next;
        }
        return -1; // 못 찾음
    }
};
 
template<typename T>
ostream& operator <<(ostream &out, const LinkedList<T> &LL){ // 원소들을 한 줄에 차례대로 출력
    ListNode<T> *temp = LL.head;
    out << '[';
    for(int i=0; i<LL.size; i++){
        out << temp->value;
        temp = temp->next;
        if(i < LL.size-1) out << ", ";
    }
    out << ']';
    return out;
}
 
int main(){
    LinkedList<int> LL;
    LL.insert(0, 1); cout << LL << endl;
    LL.insert(1, 2); cout << LL << endl;
    LL.insert(2, 3); cout << LL << endl;
    LL.insert(0, 4); cout << LL << endl;
    LL.insert(0, 5); cout << LL << endl;
    LL.insert(5, 6); cout << LL << endl;
    LL.insert(4, 7); cout << LL << endl;
    LL.insert(1, 8); cout << LL << endl;
    LL.erase(4); cout << LL << endl;
    LL.erase(0); cout << LL << endl;
    LL.erase(5); cout << LL << endl;
    LL.insert(3, 9); cout << LL << endl;
    LL.erase(1); cout << LL << endl;
    LL.insert(1, 10); cout << LL << endl;
}