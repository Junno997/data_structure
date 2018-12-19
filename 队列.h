#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

template<class T>
class Queue
{
private:
	struct Node
	{
		T item;
		struct Node * next;
	};//指针实现方法
	Node * front;
	Node * rear;
	Node * TEMP;
	int length;
	int Qsize;
	enum{Q_size=100};
	Queue(const Queue & Q);
	

public:

	explicit Queue(int Qs = Q_size);

	~Queue();
	bool isEmpty()const { return length == 0; }
	bool isFull()const { return length == Qsize; }
	int Length()const { return length; }
	int Size()const { return Qsize; }
	bool Enqueue(const T & item);
	bool Dequeue(T & item);
	void Showqueue()const;
	Queue & operator=(const Queue& Q);
	template<class T>
	friend ostream & operator<<(ostream & os,  Queue<T> & Q);
	//附加
	T First()const { return front->item; }
	T Last()const { return rear->item; }
	T Locate(int n)
	{
		if (n<1 || n>length)
		{
			cout << "Erroe input!\n";
			return false;
		}
		else
		{
			TEMP = front;
			for (int i = 1; i < n; i++)
				TEMP = TEMP->next;

			return TEMP->item;
		}
	}

	bool Insert_queue(T &item,int pos)
	{
		if (pos<1 || pos>=length)   //队尾不算插队
		{
			cout << "Erroe input!\n";
			return false;
		}
		Node *temp = new Node;
		temp->next = NULL;
		temp->item = item;
		TEMP= front;
		if (pos == 1)
		{
			temp->next = front->next;
			front = temp;
			return true;
		}
		for (int i = 1; i < pos-1; i++) {
			TEMP = TEMP->next;
		}
			
		temp->next = TEMP->next;
		TEMP->next = temp;
		length++;
		return true;

	}
};

template<class T>
inline Queue<T>::Queue(int Qs):Qsize(Qs)
{
	front = rear = NULL;
	length = 0;
}

template<class T>
inline Queue<T>::Queue(const Queue & Q)
{
	length =0;
	Qsize = Q.Size();
	Node * temp = new Node;
	temp = front;
	for (;temp!=NULL;temp=temp->next)
	{
		Enqueue(temp->item);
	}
}

template<class T>
 Queue<T> & Queue<T>::operator=(const Queue & Q)
{
	// TODO: 在此处插入 return 语句
	 if (this == &Q)return *this;
	 else
	 {
		 Queue<T>::~Queue();
		 length =0;
		 Qsize = Q.Size();
		 Node * temp = new Node;
		 temp = Q.front;
		 for (; temp != NULL; temp = temp->next)
		 {
			 Enqueue(temp->item);
		 }
		 
	 }
}

template<class T>
inline Queue<T>::~Queue()
{
	Node * temp = new Node;
	temp = front;
	while (temp != NULL)
	{
		front = temp;
		temp = temp->next;
		delete front;
	}
	//Node * temp = new Node;
	//while (front != nullptr)
	//{
	//	temp = front;
	//	front = front->next;
	//	delete temp;
	//}
}

template<class T>
inline bool Queue<T>::Enqueue(const T & item)
{
	if (isFull())
	{
		cout << "The queue is full\n";
		return false;
	}
	else
	{
		Node * add = new Node;
		add->item = item;
		add->next = NULL;
		length++;
		if (front == NULL)
			front = add;
		else
			rear->next = add;
		rear = add;
		return true;
	}
}

template<class T>
inline bool Queue<T>::Dequeue(T & item)
{
	if (isEmpty())
	{
		cout << "The queue is empty\n";
		return false;
	}
	else
	{
		item = front->item;
		length--;
		Node * temp = front;
		front = front->next;
		delete temp;
		if (length == 0)
			rear = NULL;
		return true;
	}
}

template<class T>
inline void Queue<T>::Showqueue() const
{
	Node *temp = new Node;
	temp = front;
	for (;temp!=NULL;temp=temp->next)
		cout << temp->item << "  ";
	cout << endl;
}

template<class T>
 inline ostream & operator<<(ostream & os,  Queue<T>& Q)
{
	// TODO: 在此处插入 return 语句
	 if (Q.isEmpty())
	 {
		 return os;
	 }
	 else
	 {
		 Q.TEMP = Q.front;
		 for (;Q.TEMP!=NULL; Q.TEMP = Q.TEMP->next)
			 os << Q.TEMP->item << "  ";
		 os << endl;
		 return os;
	 }
		
}
