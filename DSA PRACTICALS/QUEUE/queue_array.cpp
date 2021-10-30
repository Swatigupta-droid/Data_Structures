#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 20

template <class X>
class queue 
{
	X *arr; 		
	int capacity;   
	int front;  
	int rear;   
	int count; 

public:
	queue(int size = SIZE);		

	void dequeue();
	void enqueue(X x);
	int size();
	bool isEmpty();
	bool isFull();
	void display();
};

template <class X>
queue<X>::queue(int size)
{
	arr = new X[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

template <class X>
void queue<X>::dequeue()
{
	if (isEmpty())
	{
		cout << "UnderFlow Condition\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Removing " << arr[front] << '\n';

	front = (front + 1) % capacity;
	count--;
}

template <class X>
void queue<X>::enqueue(X item)
{
	if (isFull())
	{
		cout << "OverFlow Condition\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Inserting " << item << '\n';

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

template <class X>
int queue<X>::size()
{
	return count;
}

template <class X>
bool queue<X>::isEmpty()
{
	return (size() == 0);
}

template <class X>
bool queue<X>::isFull()
{
	return (size() == capacity);
}

template<class X>
void queue<X>::display()
{
	if(!isEmpty())
	{
		for(int i=0;i<count;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	else{
	cout<<"Underflow"<<endl;
}

}

int main()
{
	queue<int> q(10);
  int choice =0,el;  
    while(choice != 5)   
    {  
        cout<<"\n Choose an option : \n";
   cout<<"\n1.Insert\n2.Delete\n3.isFull\n4.isEmpty\n5.Display\n6.Exit";  
        cout<<"\nEnter your choice?\n";         
        cin>>choice;  
        switch(choice)  
        {  
            case 1:{  
            	cin>>el;
            	q.enqueue(el);    
            	break;
            	}  
            case 2:{  
            	q.dequeue();         
            	break;  
            }
            case 3:  
            {
            	if (q.isFull())
		            cout << "Queue Is Full\n";
	          	else
		            cout << "Queue Is Not Full\n";       
            	break;  
            }
            case 4:  
            {
            	if (q.isEmpty())
		            cout << "Queue Is Empty\n";
	          else
		            cout << "Queue Is Not Empty\n";
		    }     
            break;   
            case 6:  
            exit(0);  
            break;  
            case 5:
            {
            	q.display();
            }
            default:  
            cout<<"Please enter valid choice!!";  
        }  
    }  

	return 0;
}