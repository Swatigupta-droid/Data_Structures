#include<iostream>
using namespace std;

template<class T>
class stack
{
private:
	int n;
	T *a;
	int cursor;

public:
	stack(int size)
	{
		n=size;
		a=new T[n];
		cursor=0;
	}
	void push(T val);
	void display();
	void pop();
	
};

template<class T>
void stack<T>::push(T val)
	{
		if (cursor>=n)
			cout<<"Stack full"<<endl;
		else 
		{
			a[cursor++]=val;
		}
	}

template<class T>
void stack<T>::display()
	{
		int counter=0;
		while(counter!=cursor)
			cout<<a[counter++]<<" ";
		cout<<endl;
	}

template<class T>
void stack<T>::pop()
{
	if(cursor==0)
		cout<<"Stack empty!!"<<endl;
	else
	{
		a[cursor]=0;
		cursor=cursor-1;
		cout<<"Deleted"<<endl;
	}
}
int main()
	{
		int size,ch,val;
		cout<<"Enter the size of stack"<<endl;
		cin>>size;
		stack<int> st(size);
		char repeat;
		do{
		cout<<"MENU"<<endl;
		cout<<"1.PUSH"<<endl;
		cout<<"2.POP"<<endl;
		cout<<"3.DISPLAY"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:
			{
				cout<<"Enter the value"<<endl;
				cin>>val;
				st.push(val);
				break;
			}
			case 2:
			{
				st.pop();
				break;
			}
			case 3:
			{
				cout<<"Stack : "<<endl;
				st.display();
				break;
			}
			default:
			{
				cout<<"Wrong choice"<<endl;
				break;
			}
		}
		cout<<"Do you want to continue (Y/N)?"<<endl;
		cin>>repeat;
	}
	while(repeat=='y'||repeat=='Y');
	}