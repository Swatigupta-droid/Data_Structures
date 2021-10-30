#ifndef NAME
#define NAME
#include<iostream>
using namespace std;

template<typename T>
class Name
{
	private: 
		T data;

	public:
	Name();
	T get() const;
	void set(T data);		
};
#endif