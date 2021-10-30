#include<iostream>
using namespace std;
	int n;
	int *ar;
	int j=0;

int findSum(int A[], int N)
{
    if (N <= 0)
        return 0;
    return (findSum(A, N - 1) + A[N - 1]);
}
 

int main()
{	
	ar=new int[n];
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	cout<<"Enter the elements in the array"<<endl;
	for (int i=0;i<n;i++)
		cin>>ar[i];
	cout<<"Sum: "<<findSum(ar,n);
}