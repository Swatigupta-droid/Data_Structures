#include<iostream>
using namespace std;

template <typename T>
T smallest(const T &first,const T &second)
{
	if(first<second)
		return first;
	return second;
}
template <typename T>
T smallest(const T &first, const T &second, const T &third)
{
	if(first<second)
	{
		if(first<third)
			return first;
		else
			return second;
	}
	return third;
}
int main()
{
	int first,second,third;
	cin>>first>>second;
	cout<<smallest(first,second);
	cin>>third;
	cout<<smallest(first,second,third);
	first=1;
	second=2;
	third=3;
	cout<<smallest(1,2,3);
}