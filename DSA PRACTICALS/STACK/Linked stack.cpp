#include<iostream>
using namespace std;

template<class T>
class Stack;

template <class T>
	class Node {
	public:
		friend class Stack<T>;
		T data;
		Node<T>* pNext;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
		
	};

template <class T>
class Stack {
	Node<T>* head;
	int size;
public:
	Stack();
	~Stack();
	void pop();
	void push(T data);
	int GetSize();
	void clear();
	bool empty();
	T top();
	void display();
};

template <class T>
Stack<T>::Stack() {
	head = nullptr;
	size = 0;
}

template <class T>
Stack<T>::~Stack() {
	clear();
}

template<class T>
void Stack<T>::pop() {   // pop_front
	if (empty()) throw out_of_range("Stack is empty");
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<class T>
void Stack<T>::push(T data) {  // push_front
	head = new Node<T>(data, head);
	size++;
}

template<class T>
int Stack<T>::GetSize() {
	return size;
}

template<class T>
void Stack<T>::clear() {
	while (size) {
		pop();
	}
}

template<class T>
bool Stack<T>::empty() {
	if (size == 0) return 1;
	else return 0;
}

template<class T>
T Stack<T>::top() {
	if (empty()) throw out_of_range("Stack is empty");
	return head->data;
}

template<class T>
void Stack<T>::display()
{
	Node<T>* n=head;
	while(n!=nullptr)
	{
		cout<<n->data<<" ";
		n=n->pNext;
	}
	cout<<endl;
}

int main()
{
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.display();
	st.pop();
	st.pop();
	st.display();

}