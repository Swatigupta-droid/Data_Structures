

#include<iostream>
using namespace std;

template<class T>
class Dlink;
template<class T>
class node
{
private:
	T num;
	node* prev;
	node* next;
	friend class Dlink<T>;
};

template<class T>
class Dlink
{
public:
	Dlink();
	bool empty() const;
	void addBack(const T&);
	void removeBack();
	void swaps(int i);
	void disp();
private:
	node<T>* header;
	node<T>* trailer;
protected:
	void add(node<T>* ,const T&);
	void remove(node<T>*);
};

template<class T>
Dlink<T>::Dlink()
{
	header=new node<T>;
	trailer=new node<T>;
	header->next=trailer;
	trailer->prev=header;
}

template<class T>
bool Dlink<T>::empty() const
{
	return(header->next==trailer);
}


template<class T>
void Dlink<T>::add(node<T>* v,const T& val)
{
	node<T>* u=new node<T>;
	u->num=val;
	u->next=v;
	u->prev=v->prev;
	v->prev->next=v->prev=u;
}


template<class T>
void Dlink<T>::addBack(const T& val)
{
	add(trailer,val);
}

template<class T>
void Dlink<T>::remove(node<T>* v)
{
	node<T>* u =v->prev;
	node<T>* w =v->next;
	u->next=w;
	w->prev=u;
	delete v;
}

template<class T>
void Dlink<T>::removeBack()
{
	remove(trailer->prev);
}


template<class T>
void Dlink<T>::swaps(int i)
{
	node<T>* temp=header;
	node<T>* temp2=trailer;
	node<T>* swap=NULL;
	int counter=1,count=1;
	if(i==0)
	{
		return;
	}
	while(counter<i-1)
	{
		temp=temp->next;
		counter++;
		if(i==1)
		{
			cout<<"Invalid position"<<endl;
			return;
		}
	}
	temp=temp->next;
	cout<<temp<<endl;
	while(count<i-1)
	{
		temp2=temp2->prev;
		count++;
		if(i==1)
		{
			cout<<"Invalid position"<<endl;
			return;
		}
	}
	temp2=temp2->prev;
	cout<<temp2<<endl;
	if (temp == header || temp2 == header){
            if (temp == header){
                swap = header; //swap store header address
                header = temp2->prev->next; // the second value predecessor next is saved into header
                temp2->prev->next = swap; // the second value predecessor next points to header now

                swap = temp->prev;
                temp->prev = temp2->prev;
                temp2->prev = swap;

                swap = temp->next;
                temp->next = temp2->next;
                temp2->next = swap;
            }
            else if (temp2 == header){
                swap = header; //swap store header address
                header = temp->prev->next; // the second value predecessor next is saved into header
                temp->prev->next = swap; // the second value predecessor next points to header now

                swap = temp->prev;
                temp->prev = temp2->prev;
                temp2->prev = swap;

                swap = temp->next;
                temp->next = temp2->next;
                temp2->next = swap;
            }
        }
        else {
            if (temp == trailer){
                trailer = temp2;
            }

            else if(temp2 == trailer) {
                trailer = temp;
            }

            swap = temp->prev->next;
            temp->prev->next = temp2->prev->next;
            temp2->prev->next = swap;

            swap = temp->prev;
            temp->prev = temp2->prev;
            temp2->prev = swap;

            swap = temp->next;
            temp->next = temp2->next;
            temp2->next = swap;
        }
}

template<class T>
void Dlink<T>::disp()
{
	node<T>* h=header->next;
	while(h!=trailer)
	{
		cout<<h->num<<" ";
		h=h->next;
	}
	cout<<endl;
}


int main()
{
	Dlink<int> d;
	d.addBack(1);
	d.addBack(2);
	d.addBack(3);
	d.addBack(4);
	d.addBack(5);
	d.addBack(6);
	d.disp();
	d.swaps(3);

	d.disp();
}

