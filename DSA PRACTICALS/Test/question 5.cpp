#include<iostream> 
using namespace std;
template<class T>
class Stack;
template<class T>
class Pall;
template<class T>
class node
{
	T data;
	node<T>*next;
	node()
	{
		next=NULL;
	}
	friend class Pall<T>;
	friend class Stack<T>;
};
template<typename T>
class Stack
{
	node<T> *front;
	public:
		Stack();
		bool isEmpty();
		void push(T&);
		void pop();
		T top();
		
};
template<typename T>
Stack<T>::Stack()
{
	front=NULL;
}
template<class T>
bool Stack<T>::isEmpty()
{
	return front==NULL;
}
template<class T>
void Stack<T>::push(T&el)
{
	node<T>*temp=new node<T>;
	temp->data=el;
	if(isEmpty())
	{
		temp->next=NULL;   
	}
	else
	{
	   temp->next=front;	
	}
	front=temp;
}
template<class T>
void Stack<T>::pop()
{
	if(isEmpty())
	{
		return;
	}
	else
	{
		node<T>*temp=front;
		front=front->next;
		delete(temp);
	}
}
template<class T>
T Stack<T>::top()
{
	if(isEmpty())
	{
		return -1;
	}
	return front->data;
}
template<class T>
class Pall
{
	node<T>*head;
	public:
		Pall()
		{
			head=NULL;
		}
	void add(T ele);
	bool chec();
	void display();
};

template<class T>
void Pall<T>::add(T ele)//front
{
	node<T>*temp=new node<T>;
	temp->data=ele;
	if(head==NULL)
	{
		head=temp;
		return;
	}
	temp->next=head;
	head=temp;	
}
template<class T>
void Pall<T>::display()
{
	node<T> *temp=head;
	if(temp==NULL)
		cout<<"list is empty!"<<endl;
    cout<<"\n**LINKED LIST ELEMENTS**"<<endl;
	cout<<"------------------------------"<<endl;		
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
template<class T>
bool Pall<T>::chec()
{   Stack<T>s;
    node<T>*temp=head;
	node<T>*n=head;
	while(n!=NULL)
	{
		s.push(n->data);
		n=n->next;
	}
	while(temp!=NULL)
	{
		T i=s.top();
		s.pop();
		if(temp->data!=i)
		{
			return false;
		}
		temp=temp->next;
	}
return true;	
}
int main()
{
	int res;
	Pall<char>p;
	p.add('a');
	p.add('b');
	p.add('c');
	p.add('b');
	p.add('a');
	p.add('g');
	//p.add('f');
	p.display();
	res=p.chec();
	if(res==1)
	{
		cout<<"\nList of characters is pallindrome";
	}
	else
	{
		cout<<"\nList of characters is not Pallindrome";
	}
}