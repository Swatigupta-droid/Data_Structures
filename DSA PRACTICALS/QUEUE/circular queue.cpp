#include<iostream>
using namespace std;
template<class T>
class cqueue;
template<class T>
class node{
	T data;
	node<T>*next;
	friend class cqueue<T>;
};
template <class T>
class cqueue
{
	node<T>*cursor;
	public:
		cqueue();
		void advance();
		const T& front() const;
		void enqueue(const T &);
		void dequeue();
		void display();
		bool isEmpty();
		
};
template<class T>
cqueue<T>::cqueue()
{
	cursor=NULL;
}
template<class T>
bool cqueue<T>::isEmpty()
{
	return cursor==NULL;
}
template<class T>
void cqueue<T>::advance()
{
	cursor=cursor->next;
}
template<class T>
void cqueue<T>::enqueue(const T &e)
{
	node<T>* temp=new node<T>;
	temp->data=e;
	if(isEmpty())
	{
		cursor=temp;
		cursor->next=temp;
	}
	else
	{
		temp->next=cursor->next;
		cursor->next=temp;
		advance();
	}
	cout<<"\nElement Enqueued";
		
}
template<class T>
void cqueue<T>::dequeue()
{
	if(isEmpty())
	{
		cout<<"\nQueue is empty!"<<endl;
		return;
	}
	node<T>* temp=cursor->next;
	if(temp==cursor)
		cursor=NULL;
	else
		cursor->next=temp->next;
	delete temp;
	cout<<"\nElement Dequeued";
}
template<class T>
const T& cqueue<T>::front() const
{
	return cursor->next->data;
}
template<class T>
void cqueue<T>::display()
{
	cout<<"*\nQueue Elements*"<<endl;
	if(isEmpty())
	{
		cout<<"\nQueue is empty!"<<endl;
		return;
	}
	else
	{
		node<T>*temp=cursor->next;
		while(temp!=cursor)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<cursor->data<<endl;
	}
	cout<<endl;
}
int main()
{
	cqueue<int>myqueue;
	int choice;
	while(true)
	{
		cout<<"\n\n**MENU**";
		cout<<"\n------------";
		cout<<"\n1.Enqueue\n2.dequeue\n3.Get the top element\n4.display";
	    cout<<"\n5.Exit from the program";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: int e;
			        cout<<"\nEnter the element you want to insert: ";
			        cin>>e;
			        myqueue.enqueue(e);
                    break;
                    
            case 2: myqueue.dequeue();
                    break;
			
			case 3: cout<<"Top element: "<<myqueue.front();
					break;
					
		    case 4:	myqueue.display();
			        break;
			        
		    case 5: exit(0);
			        break;
		    default: 
			        cout<<"\nWrong choice!!";
					break;									
					
			}	
	}
}