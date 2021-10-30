#ifndef FUN1
#define FUN1
#include "fun.h"

template<typename T>
fun<T>::fun(T d)
:data(d)
{

}
template<typename T>
fun<T>::~fun()
{

}
template<typename T>
T fun<T>::get () const
{
	return data;
}
template<typename T>
void fun<T>::set(T d)
{
	data =d;
}
#endif