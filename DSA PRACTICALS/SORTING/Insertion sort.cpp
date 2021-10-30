#include<iostream>
using namespace std;

template<class T>
class Insertionsort
{
	T *arr;
	int n;
	int c;
	public :
	Insertionsort(int size)
	{
		n=size;
		arr=new T [size];
		c=0;
	}
	void input();//takes input
	void display();//displays the results
	void sort();//sorts the array
};

template<class T>
void Insertionsort<T>::input()
{
	cout<<"Enter the elements in the array"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
}

template<class T>
void Insertionsort<T>::display()
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

template<class T>
void Insertionsort<T>::sort()
{
	T key,i,j,c=0;
	for(j=1;j<n;j++)
	{
		key=arr[j];
		i=j-1;
		
		while(i>=0&&arr[i]>key)
		{
			c++;//calculating the total number comparisons
			arr[i+1]=arr[i];
			i=i-1;
			cout<<"Intermediate result"<<endl;//printing the intermediate result
		for(int f=0;f<n;f++)
			cout<<arr[f]<<" ";
		cout<<endl;
		}
		
		arr[i+1]=key;
		if(key>arr[i])
		{
			c++;
		}
		
	}
		cout<<"The total number of comparisons are "<<c<<endl;
	
}

int main()
{
	int size;
	cout<<"Enter the size of the array"<<endl;
	cin>>size;
	Insertionsort<int> ins(size);
	ins.input();
	cout<<"Array before sorting "<<endl;
	ins.display();
	ins.sort();
}