#include<iostream>
using namespace std;

template<class T>
class binary
{
       public:
       T *arr; int n,i;   
        binary(int N)
        {
            n=N;
            arr=new T[n];
            i=0;
        }
        void set(T &val);
        int bSearch(T arr[],int l,int u,T x);
};

template<class T>
void binary<T>::set(T &val)
{
    arr[i]=val;
    i++;
}

template<class T>
int binary<T>::bSearch(T arr[],int l,int u,T x)
{
    if(u>=l)
	{
		int mid=l+(u-1)/2;
		if(arr[mid]==x)
			return mid;
		if(arr[mid]<x)
			return bSearch(arr,mid+1,u,x);

		return bSearch(arr,0,mid-1,x);
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
    
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    binary <int> b1(n);
    for(int i=0;i<n;i++)
    {
        b1.set(arr[i]);
    }
    int x;
    cout<<"Enter the value to be searched"<<endl;
    cin>>x;
    int pos=b1.bSearch(b1.arr,0,n-1,x);
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