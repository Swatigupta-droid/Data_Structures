#include<iostream>
using namespace std;
template<typename T>
class SinglyLinked;
template<typename T>
class node
{
	private:
		T data;
		node<T>*next;
		friend class SinglyLinked<T>;
		
};

template<typename T>
class SinglyLinked{
	public:
		SinglyLinked();
		~SinglyLinked();
		bool empty()const;
		const T&front() const;
		void addFront(const T& ele );
		void removeFront();
		void display();
   private: 
       node<T>*head;

   		
};

template<typename T>
SinglyLinked<T>::SinglyLinked()
   {
   	head=NULL;
   	
   		
   }
template<typename T>
bool SinglyLinked<T>::empty()const
    {
     	return head==NULL;
	}  
	
template<typename T>
const T&SinglyLinked<T>	::front()const
{
	return head->data;
}
template<typename T>
SinglyLinked<T>::~SinglyLinked()
{
	while(!empty())
	 removeFront();
}
template<typename T>
void SinglyLinked<T>::addFront(const T& ele )
{
    node<T>*temp=new node<T>;
	temp->data=ele;
	temp->next=head;
	head=temp;
}

template<typename T>
void SinglyLinked<T>::removeFront()
{
	node<T>*temp=head;
	head=temp->next;
	delete temp;
}
template<typename T>
void SinglyLinked<T>::display()
{
node<T>*temp=head;
	if(temp==NULL)
	{
		cout<<"\nList is Empty!!";
	}
	while(temp->next->next!=NULL)
	{
		cout<<temp->data<<"-->";
		temp=temp->next;
   }
}

	    
int main()
{
	SinglyLinked<int>b;
	b.addFront(13);
	b.addFront(36);
		b.addFront(76);
	b.display();
	cout<<endl;
	b.removeFront();

	b.display();
}