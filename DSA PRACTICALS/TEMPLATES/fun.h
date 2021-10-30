#ifndef FUN
#define FUN
#include<iostream>
using namespace std;

template<typename T>
class fun
{
private:
	T data;
public:
	fun(T data);
	~fun();
	T get() const;;
	void set(T data);
};
#endif