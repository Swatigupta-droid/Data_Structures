#include<iostream>
#include<vector>
using std::vector;
using namespace std;

template<class T>
class vec
{
public:
	int n;
	int size;
	vector<T> v;
	vec(int n)
	{
		this->n=n;
		 vector<T> v(n);
	}
	void push();
	void pop();
	void display();
};

template<class T>
void vec<T>::push()
{
	T val;
	size=v.size();
	if(size==n)
	{
		v.reserve(2*n);
		n*=2;
	}
		cout<<"Enter the value to be pushed"<<endl;
		cin>>val;
		v.push_back(val);
		size=v.size();
	
}

template<class T>
void vec<T>::pop()
{
	if(v.empty())
	{
		cout<<"Underflow!!"<<endl;
	}
	else
	{
		cout<<"Last element is "<<v.back()<<endl;
		v.pop_back();
		size=v.size();
	}
}

template<class T>
void vec<T>::display()
{
	if(v.empty())
	{
		cout<<"Underflow!!!"<<endl;
		v.resize(n);
	}
	else
	{
		int i;
		cout<<"Enter a particular index: "<<endl;
		cin>>i;
		cout<<"The element is : "<<v[i]<<endl;

		cout<<"Vector : "<<endl;
		for(int i=0;i<size;i++)
		{
			cout<<v.at(i)<<" ";
		}
		cout<<endl;
		cout<<"Peek element is : "<<v.front()<<endl;

	}
}


int main()
{
	int n;char c;
	cout<<"Enter the size"<<endl;
	cin>>n;
	vec <int> v(n);
	do
	{
		int ch;
		cout<<"Menu"<<endl;
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.display"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1:
			{
				v.push();
				break;
			}
			case 2:
			{
				v.pop();
				break;
			}
			case 3:
			{
				v.display();
				break;
			}
			default:
			{
				cout<<"Wromg choice"<<endl;
				break;
			}
		}
		cout<<"Do you want to continue(Y/N)?"<<endl;
		cin>>c;
	}
	while(c=='Y'||c=='y');
	return 0;
}