#include<iostream>
using namespace std;


class Insertionsort
{
	int arr[9]={12, 14, 9, 18, 120, 30, 40, 35, 60};
	int n;
	int c;
	public :
	Insertionsort()
	{
		n=9;
		c=0;
	}
void display()
{
	for(int i=0;i<9;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void sort()
{
	int key,i,j,c=0;
	for(j=1;j<9;j++)
	{
		key=arr[j];
		i=j-1;
		
		while(i>=0&&arr[i]>key)
		{
			arr[i+1]=arr[i];
			i=i-1;
		}
		cout<<"Intermediate result"<<endl;//printing the intermediate result
		for(int f=0;f<9;f++)
			cout<<arr[f]<<" ";
		cout<<endl;
		
		arr[i+1]=key;
		
	}
	cout<<"Final result: "<<endl;
	for(int f=0;f<9;f++)
			cout<<arr[f]<<" ";
		cout<<endl;
		
	
}
};

int main()
{
	Insertionsort ins;
	cout<<"Array before sorting "<<endl;
	ins.display();
	ins.sort();
}