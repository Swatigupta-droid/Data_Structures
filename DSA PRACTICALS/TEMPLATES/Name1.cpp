#include<iostream>
using namespace std;
#ifndef NAME1
#define NAME1 
#include "Name.h"

template<typename T>
T Name<T>::get() const
{
	return data;
}
template<typename T>
void Name<T>::set(T d)
{
	data=d;
}
#endif