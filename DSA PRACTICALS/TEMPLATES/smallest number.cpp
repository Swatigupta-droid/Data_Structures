#include <iostream>
using namespace std;
// Definition of a template function
template <typename T>
T smaller (T first, T second)
{
if (first < second)
{
return first;
}
return second;
}
int main ( )
{
cout << "Smaller of a and B: " << smaller ('a', 'B') << endl;
cout << "Smaller of 12 and 15: " << smaller (12, 15) << endl;
cout << "Smaller of 44.2 and 33.1: " << smaller (44.2, 33.1) << endl;
return 0;
}