#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

//#ifndef DEQUE_H_
//#define DEQUE_H_
template <typename T>
class deque
{
		T* a;
		long long int asize = 5;
		long long int osize;
		long long int rear = -1;
		long long int before = -1;

//#include "deque.h"
//template <typename T>
public:
deque()
{
	a = new T[asize];
	rear = -1;
	before = -1;
}

deque(long long int n)
{
	asize = n;
	a = new T[n];
	rear = -1;
	before = -1;
}
//template <typename T>
deque(long long int n, T x)
{
	if(n > 0)
	{
		asize = n;
		a = new T[asize];
	
		for(long long int i = 0;i<n;i++)
		{
			a[i] = x;		
		}
		before = 0;
		rear = n-1;
	}
	else
	{
		before = -1;
		rear = -1;
	}
}

//template <typename T>
void push_back(T number)
{
	if((rear+1)%asize == before)
	{
		modifyarray();
		rear = (rear+1)%asize;
		a[rear] = number;
	}
	else
	{
		if(rear == -1)
		{
			before = 0;
			rear = 0;
			a[rear] = number;
		}
		else
		{
			rear = (rear+1)%asize;
			a[rear] = number;
		}
	}
}

//template <typename T>
void pop_back()
{
	try	
	{
	
	if(rear == -1)
	{
	//	cout<<"The queue is empty"<<endl;
		throw underflow_error("Underflow");
	}
	else
	{
		if(before== rear)
		{
			before = -1;
			rear = -1;
		}
		
		else
		{
			if(rear == 0)
			{
				rear = asize -1;
			}
			else
				rear = rear -1;
		}
	}
	}
	catch(underflow_error& ex)
	{
		cout<<ex.what()<<endl;
	}
}

//template <typename T>
void push_front(T number)
{
	if((rear+1)%asize == before)
	{
		modifyarray();
		if(before == 0)
		{
			before = asize -1;
			a[before] = number;
		}
		else
		{
			before = before -1;
			a[before] = number;			
		}
	}
	else
	{
		if(before == -1)
		{
			before = 0;
			rear = 0;
			a[before] = number;
		}
		else
		{
			if(before == 0)
			{
				before = asize -1;
				a[before] = number;
			}
			else
			{
				before = before -1;
				a[before] = number;
			}
		}
	}
}

//template <typename T>
void pop_front()
{
	try
	{
	if(before == -1)
	{
		//cout<<"The queue is empty"<<endl;
		throw underflow_error("Underflow");
	}
	else
	{
		if(before == rear)
		{
			before = -1;
			rear = -1;
		}
		else
		{
			if(before == asize -1)
			{
				before = 0;
			}
			else
			{
				before = before +1;
			}
		}
	}
	}
	catch(underflow_error& ex)
	{
		cout<<ex.what()<<endl;
	}
}

//template <typename T>
T front()
{
	try
	{
	if(before == -1)
	{
		//cout<<"The queue is empty"<<endl;
		throw underflow_error("Underflow");
		//return 0;
	}
	else
	{
		return a[before];
	}
	}
	catch(underflow_error& ex)
	{
		cout<<ex.what()<<endl;
		static T value;
		return value;
	}
}

//template <typename T>
T back()
{
	try
	{
	if(rear == -1)
	{
	//	cout<<"The queue is empty"<<endl;
	//	return 0;
		throw underflow_error("Underflow");
	}
	else
	{
		return a[rear];
	}
	}
	catch(underflow_error& ex)
	{
		cout<<ex.what()<<endl;
		static T value;
		return value;
	}
}

//template <typename T>
bool empty()
{
	if(rear == -1 || before == -1)
		return true;
	else
		return false;
}

//template <typename T>
long long int size()
{
	long long int s = 0;
	if(rear == -1)
	{
		return 0;
	}
	else
	{
		if(before <= rear)
		{
			for(long long int i = before; i<=rear; i++)
				s++;
		}
		if(before > rear)
		{
			for(long long int i = 0; i<=rear;i++)
			{
				s++;
			}
			for(long long int i = before; i<asize;i++)
			{
				s++;
			}
		}
	}
	return s;
}

//template <typename T>
void resize(long long int x)
{
//	cout<<rear<<endl;
//	cout<<before<<endl;
	if(rear == -1 && before == -1)
	{
		a = new T[x];
		long long int j = 0;
		for(long long int i=0; i<x; i++)
		{
			static T value;
			a[i] = value;
		}	
		rear = x-1;			 
		before = 0;
	//	cout<<before<<endl;
	//	cout<<rear<<endl;
	}
	if(before <= rear)
	{
		T* b;
		b = a;
		a = new T[x];
		int length = 0;
		for(long long int i = before; i<=rear;i++)
			length++;
		if(x <= length)
		{
			long long int j = 0;
			for(long long int i=before; i<(before+x); i++)
			{
				a[j++] = b[i];
			}	
			rear = j-1;			 
		}
		if(x>length)
		{
			long long int r = x - length;
			long long int j =0;
			for(long long int i = before; i<=rear; i++)
			{
				a[j++] = b[i];
			}			
			for(long long int i = 0;i<r;i++)
			{
				static T value;
				a[j++] = value;
			}
			rear = j-1;
		}
		before = 0;
	}
	else
	{
		modifyarray();
		T* b;
		b = a;
		a = new T[x];
		int length = 0;
		for(long long int i = before; i<=rear;i++)
			length++;
		if(x <= length)
		{
			long long int j = 0;
			for(long long int i=before; i<(before+x); i++)
			{
				a[j++] = b[i];
			}	
			rear = j-1;			 
		}
		if(x>length)
		{
			long long int r = x - length;
			long long int j =0;
			for(long long int i = before; i<rear; i++)
			{
				a[j++] = b[i];
			}			
			for(long long int i = 0;i<r;i++)
			{
				static T value;
				a[j++] = value;
			}
			rear = j-1;
		}
		before = 0;
	}
}

//template <typename T>
void clear()
{
	before = -1;
	rear = -1;
}

//template <typename T>
T operator[](long long int n)
{
	return a[(before+n)%asize];
}

long long int begin()
{
	return before;
}

long long int end()
{
	return rear;
}

long long int dequesize()
{
	return asize;
}
//template <typename T>
void modifyarray()
{
	long long int osize = asize;
	asize = 2*asize;
	T b[osize];
	//b = a;
	for(long long int i = 0; i<osize;i++)
	{
		b[i]=a[i];
	//	cout<<b[i]<<" ";
	}
//	cout<<endl;
	//	cout<<before<<endl;
	//	cout<<rear<<endl;
	a = new T[asize];
	
	if(before<=rear)
	{
		for(long long int i = before; i<=rear;i++)
		{
			a[i] = b[i];
		//	cout<<b[i]<<" ";
		}					
	}
	else
	{
		for(long long int i = before; i<osize;i++)
		{
			a[i] = b[i];
		//	cout<<b[i]<<" ";
		}
	//	cout<<"rear"<<rear<<endl;
		for(long long int i = rear; i >=0;i--)
		{
			a[i+osize] = b[i];
		//	cout<<b[i]<<" ";
		}
		rear = rear + osize;
	}
}

void display()
{
		if(before <= rear)
		{
			for(long long int i = before; i<=rear; i++)
				cout<<a[i]<<" ";
		}
		if(before > rear)
		{
			for(long long int i = 0; i<=rear;i++)
			{
				cout<<a[i]<<" ";
			}
			for(long long int i = before; i<asize;i++)
			{
				cout<<a[i]<<" ";
			}
		}
	cout<<endl;
}
};
