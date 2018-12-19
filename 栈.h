#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

template<typename T>
class Stack
{
public:
	explicit Stack(int ss=Max);
	
	~Stack()
	{
		delete[] items;
	}

	bool isEmpty()const { return top == 0; }
	bool isFull()const { return top == stacksize; }
	bool push(const T & item);
	bool pop(T & item);
	T Gettop(T & item) { return items[top]; }
	void Showstack()const;
	void Clear(int n=Max);
	void Clear(int front, int rear, int value);
	template<class T>
	friend ostream & operator << (ostream & os, const Stack<T> &S);

	//copy and construct
	Stack(const Stack & st);
	Stack & operator =(const Stack & st);

	//附加
	int Length()const { return top; }
	bool Reverse();
	bool Reverse(int front, int rear );

private:
	enum { Max = 100 };
	int stacksize;
	T * items;
	int top;



};

template<typename T>
inline Stack<T>::Stack(int ss):stacksize(ss),top(0)
{
	items = new T[stacksize];
}

template<typename T>
inline bool Stack<T>::push(const T & item)
{
	if (isFull())
	{
		return false;
	}
	else
	{
		items[top++] = item;
		return true;
	}
		
}

template<typename T>
inline bool Stack<T>::pop(T & item)
{
	if (isEmpty())
		return false;
	else
	{
		item = items[--top];
		return true;
	}
}

template<typename T>
inline void Stack<T>::Showstack() const
{
	for (int i = 0; i < top; i++)
		cout << items[i] << "  ";
	cout << endl;
}

template<typename T>
inline void Stack<T>::Clear(int n)
{
	Stack<T>::~Stack();
	stacksize = n;
	items = new T[stacksize];
	top = 0;
}

template<typename T>
inline void Stack<T>::Clear(int front, int rear, int value)
{
	if (isEmpty() || front<1 || rear>top)
		return;
	else
	{
		for (int i = front; i <= rear; i++)
			items[i - 1] = value;
		return;
	}
}

template<typename T>
inline Stack<T>::Stack(const Stack & st)
{
	stacksize = st.stacksize;
	top = st.top;
	items = new T[stacksize];
	for (int i = 0; i < stacksize; i++)
		items[i] = st.items[i];
}

template<typename T>
Stack<T> & Stack<T>::operator=(const Stack & st)
{
	// TODO: 在此处插入 return 语句
	if (this == &st)
		return;
	else
	{
		Clear(st.stacksize);
		top = st.top;
		for (int i = 0; i < stacksize; i++)
			items[i] = st.items[i];
		return *this;
	}
}

template<typename T>
inline bool Stack<T>::Reverse()
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		int counts = top / 2;
		for (int i = 0; i < counts; i++)
		{
			T temp;
			temp = items[i];
			items[i] = items[top - 1 - i];
			items[top - 1 - i] = temp;
		}
		return true;
	}
}

template<typename T>
inline bool Stack<T>::Reverse(int front, int rear)
{
	if (isEmpty()||front<1||rear>top)
		return false;
	else
	{

		int counts = (rear - front + 1) / 2;
		for (int i = 0; i < counts; i++)
		{
			T temp;
			temp = items[i+front];
			items[i] = items[rear - i];
			items[rear - i] = temp;
		}

		return true;

	}
}

template<class T>
inline ostream & operator<<(ostream & os, const Stack<T>& S)
{
	// TODO: 在此处插入 return 语句
	if (S.isEmpty())
	{
		cout << "The original stack is empty\n";
	}
	else
	{
		for (int i = 0; i < S.top; i++)
			os << S.items[i] << "  ";
		os << endl;
	}
	return os;
}
