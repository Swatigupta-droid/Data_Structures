#include <iostream>
using namespace std;
// Definition of template function
template <typename T>
void exchange (T& first, T& second)
{
T temp = first;
first = second;
second = temp;
}
int main ()
{
// Swapping two int types
int integer1 = 5;
int integer2 = 70;
exchange (integer1, integer2);
cout << "After swapping 5 and 70: ";
cout << integer1 << " " << integer2 << endl;
// Swapping two double types
double double1 = 101.5;
double double2 = 402.7;
exchange (double1, double2);
cout << "After swapping 101.5 and 402.7: ";
cout << double1 << " " << double2 << endl;
return 0;
}