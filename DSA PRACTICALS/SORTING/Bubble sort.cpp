#include<iostream>
using namespace std;

template<class T>
class sorting
{
	int n;
	T *a;
	int c;
public:
	sorting(int size)
	{
		n=size;
		a=new T[n];
	}
	void input();//taking inputs
	void display();//to display the result
	void BubbleSort();//to sort the array using bubble sort and find the number of comparisons
};

template<class T>
void sorting<T>::input()
{
	for(int i=0;i<n;i++)
		cin>>a[i];
}

template<class T>
void sorting<T>::BubbleSort()
{
	int i,j,f=0,sum=0;//f is for the pass number
	for(i=n;i>1;i--)
	{
		c=0;
		for(j=0;j<i-1;j++)
		{
			c++;//number of comparisons
			if(a[j]>a[j+1])
				{
					T temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
					cout<<"Intermediate array ";
					display();
				}
		}
		++f;sum+=f;//calculating the total number of comparisons
		cout<<endl<<"The number of comparisons is "<<c<<endl;
		cout<<"Pass number "<<f<<endl;
		//printing the intermediate result
	}
	cout<<" Total number of comparisons is "<<+sum<<endl;
}
template<class T>
void sorting<T>::display()
{
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main()
{
	int size;
	cout<<"Enter the size of array"<<endl;
	cin>>size;
	sorting<int> sort(size);
	cout<<"Enter the elements in the array "<<endl;
	sort.input();
	cout<<endl<<"The array before sorting is";
	sort.display();
	sort.BubbleSort();
	cout<<endl<<"The array after sorting is ";
	sort.display();

}