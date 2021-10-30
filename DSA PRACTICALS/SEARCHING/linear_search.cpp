#include<iostream>
using namespace std;

template<class T>
class linear
{
       public:
       T *arr; int n,i;   
        linear(int N)
        {
            n=N;
            arr=new T[n];
            i=0;
        }
        void set(T &val);
        int lSearch(T x);
};

template<class T>
void linear<T>::set(T &val)
{
    arr[i]=val;
    i++;
}

template<class T>
int linear<T>::lSearch(T x)
{
   for(int i=0;i<n;i++)
   {
       if(arr[i]==x)
        return i;
   }
   return -1;
}

int main()
{
    int n;int *arr;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    arr=new int[n];
    cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    linear <int> b1(n);
    for(int i=0;i<n;i++)
    {
        b1.set(arr[i]);
    }
    int x;
    cout<<"Enter the value to be searched"<<endl;
    cin>>x;
    int pos=b1.lSearch(x);
    if(pos==-1)
    {
        cout<<"Element does not exist in the array"<<endl;
    }
    else
    {
        cout<<"Element exists in the position "<<pos<<endl;
    }
    return 0;
}