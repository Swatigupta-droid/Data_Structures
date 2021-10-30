#include<iostream>
using namespace std;

template<class T>
class Clink;

template<class T>
class node
{
private:
	T data;
	node<T>* next;
	friend class Clink<T>;
};

template<class T>
class Clink
{
public:
	Clink();
	~Clink();
	bool empty() const;
	const T& front() const;
	const T& back() const;
	void advance();
	void addfront(const T& val);
	void addBack(const T& val);
	void add_at_pos(const T& val,T );
	void remove_x(const T& );
	void removefront();
	void removeback();
	node<T>* search(const T&);
	void display();
	void concatenate(node<T>*);
	node<T>* ptrfront();
private:
	node<T>* cursor;
};

template<class T>
Clink<T>::Clink():cursor(NULL)
{}

template<class T>
Clink<T>::~Clink()
{
	while(!empty())
		removefront();
}

template<class T>
bool Clink<T>::empty() const
{
	return cursor==NULL;
}

template<class T>
const T& Clink<T>::back() const
{
	return cursor->next;
}

template<class T>
const T& Clink<T>::front() const
{
	return cursor->next->data;
}
template<class T>
void Clink<T>::advance()
{
	cursor=cursor->next;
}
template<class T>
void Clink<T>::addfront(const T& val) //add front
{
	node<T>* n=new node<T>;
	n->data=val;
	if(cursor==NULL)
	{
		n->next=n;
		cursor=n;
	}
	else
	{
		n->next=cursor->next;
		cursor->next=n;
	}
}

template<class T>
void Clink<T>::removefront()
{
	node<T>* old=cursor->next;
	if(old==cursor)
		cursor=NULL;
	else
		cursor->next=old->next;
	delete old;
}

template<class T>
void Clink<T>::display()
{
	if(empty()){
		cout<<"Underflow!!"<<endl;
		return;
	}
	else
	{
		node<T>*n=cursor->next;
		while(n!=cursor)
		{
			cout<<n->data<<" ";
			n=n->next;
		}
		cout<<cursor->data<<endl;
	}
	cout<<endl;
}

template<class T>
void Clink<T>::add_at_pos(const T& val,const T y)
{
	node<T>* n=new node<T>;
	node<T>* h=cursor->next;
	while(h->data!=y)
		h=h->next;
	n->data=val;
	n->next=h->next;
	h->next=n;
}

template<class T>
void Clink<T>::addBack(const T& val) //add back
{
	node<T>* n=new node<T>;
	n->data=val;
	if(cursor==NULL)
	{
		cursor=n;
		cursor->next=n;
		return;
	}
	else
	{
		n->next=cursor->next;
		cursor->next=n;
		advance();
	}
}

template<class T>
void Clink<T>::removeback()
{
	node<T>* old=cursor;
	if(cursor->next==cursor)
		cursor=NULL;
	else
		{
			node<T>* n=cursor->next;
			while(n->next!=cursor)
			{
				n=n->next;
			}
			n->next=old->next;
			cursor=n;
		}
	delete old;
}

template<class T>
void Clink<T>::remove_x(const T& x)
{

	node<T>* h=cursor->next;
	while(h->next->data!=x){
		h=h->next;
		cout<<"Maybe not present!! checking"<<endl;
		return;
	}

	node<T>* old=h->next;
	h->next=h->next->next;
	delete old;
}

template<class T>
node<T>* Clink<T>::search(const T& y)
{
	node<T>* h=cursor->next;
	while(h->data!=y)
		h=h->next;
	return h;
}

template<class T>
void Clink<T>::concatenate(node<T>* head)
{
	node<T>* n=head->next;
	while(n->next!=head)
		n=n->next;
	n->next=cursor->next;
	cursor->next=head;
	node<T>* h=head->next->next;
	while(h->next->next!=cursor->next)
		advance();
}

template<class T>
node<T>* Clink<T>::ptrfront()
{
	return cursor->next;
}

int main()
{
	Clink<int> c;
	Clink<int> d;

	int ch; char repeat;
	int val,y;
	do{
	cout<<"Menu"<<endl;
	cout<<"1.Insert an element x at the front of the circularly linked list"<<endl;
	cout<<"2.Insert an element x after an element y in the circularly linked list"<<endl;
	cout<<"3.Insert an element x at the back of the circularly linked list"<<endl;
	cout<<"4.Remove an element from the back of the circularly linked list"<<endl;
	cout<<"5.Remove an element from the front of the circularly linked list"<<endl;
	cout<<"6.remove the element x from the circularly linked list"<<endl;
	cout<<"7.Search for an element x in the circularly linked list and return its pointer"<<endl;
	cout<<"8.Concatenate two circularly linked lists"<<endl;
	cout<<"9.Display"<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>ch;

	switch(ch)
	{
		case 1:
		{
			cout<<"Enter the value"<<endl;
			cin>>val;
			c.addfront(val);
			break;
		}
		case 2:
		{
			cout<<"Enter the value to be entered"<<endl;
			cin>>val;
			cout<<"Enter the position element"<<endl;
			cin>>y;
			c.add_at_pos(val,y);
			break;
		}
		case 3:
		{
			cout<<"Enter the value"<<endl;
			cin>>val;
			c.addBack(val);
			break;
		}
		case 4:
		{
			c.removeback();
			break;
		}
		case 5:
		{
			c.removefront();
			break;
		}
		case 6:
		{
			cout<<"Enter the value to be deleted"<<endl;
			cin>>val;
			c.remove_x(val);
			break;
		}
		case 7:
		{
			cout<<"Enter the element to be searhed"<<endl;
			cin>>val;
			cout<<"Pointer : "<<c.search(val)<<endl;
			break;
		}
		case 8:
		{
			cout<<"Enter second list "<<endl;
			repeat='y';
			while(repeat=='Y'||repeat=='y')
			{
				cout<<"Enter the value"<<endl;
				cin>>val;
				d.addBack(val);
				cout<<"Do you want to enter more (Y/N)?"<<endl;
				cin>>repeat;
			}
			c.concatenate(d.ptrfront());
			break;
		}
		case 9:
		{
			c.display();
			break;
		}
		default:
		{
			cout<<"Wrong choice!!"<<endl;
			break;
		}
	}
	cout<<"Do you want to continue(Y/N)? "<<endl;
	cin>>repeat;
}
while(repeat=='Y'||repeat=='y');
}

