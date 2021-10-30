#include<iostream>
using namespace std;

template <typename T,int N>

void print(T (&arr)[N])
{
	for(int i=0;i<N;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main ()
{
	int arr1[4]={1,2,3,4};
	double arr2[2]={1.3,6.7};
	print(arr1);
	print(arr2);
}