#ifndef SMALLER
#define SMALLER
#include<iostream>
using namespace std;

template<typename T>
T smaller(const T &first,const T &second)
{
	if(first<second)
		return first;
	return second;
}
#endif