#include<iostream>
#include<string>
#include<cstring>
using namespace std;

template <typename T>

const T& smaller(const T&first,const T&second)
{
	if(first<second)
		return first;

	return second;

}
template <>
 const char* const& smaller<const char*> (const char* const& first , const char* const& second)
 {
 	if(strcmp(first,second)<0)
 		return first;

 	return second;
 }
 int main()
 {
 	string s1="hello",s2="no";
 	cout<<smaller(s1,s2);

 	const char* c1="hey hii";
 	const char* c2="hello" ;
 	cout<<smaller<>(c1,c2);
 	return 0;

 }