#include<iostream>
using namespace std;

template<class T>
class Selectionsort
{
	T *arr;
	int n;
	
	int c;
	public :
	Selectionsort(int size)
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
void Selectionsort<T>::input()
{
	cout<<"Enter the elements in the array"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
}

template<class T>
void Selectionsort<T>::display()
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

template<class T>
void Selectionsort<T>::sort()
{
	 c=0;
	for (int i = 0,j,least; i < n-1; i++) 
	{
	for (j = i+1, least = i; j < n; j++)
		{
		 c++;
		 if (arr[j] < arr[least])
			 least = j;
		}
	T sw= arr[least];
	arr[least]=arr[i];
	arr[i]=sw;
	cout<<"Intermediate result"<<endl;
	for(int k=0;k<n;k++)
		cout<<arr[k]<<" ";
	cout<<endl;
	}
	cout<<"The number of comparisons is "<<c<<endl;
}


int main()
{
	int size;
	cout<<"Enter the size of the array"<<endl;
	cin>>size;
	Selectionsort<int> ins(size);
	ins.input();
	cout<<"Array before sorting "<<endl;
	ins.display();
	ins.sort();
}


