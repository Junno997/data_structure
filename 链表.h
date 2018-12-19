#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
struct Node
	{
		T item;
		struct Node * next;
	};

template<class T>
class Linklist
{
private:
	
	enum{List_Max_Size=100};	
	Node<T> * front;
	Node<T> * rear;
	int lengths;
	int listsize;

public:
	Linklist(int Ls = List_Max_Size);
	~Linklist();
	Linklist(const Linklist&L);
	Linklist & operator =(const Linklist & L);
	bool isEmpty()const { return lengths == 0; }
	bool isFull()const { return lengths == List_Max_Size; }
	int Length()const { return lengths; }
	bool Insert(int k, T & item);
	bool Delete(int k,T & item);
	void Clear_List();
	bool Insert(T & item);//右侧添加
	bool Find_poi(int k, T &x)const;
	bool Find_item(const T & x)const;
	void ShowList()const;
};

template<class T>
inline Linklist<T>::Linklist(int Ls): listsize(Ls)
{
	front = rear = nullptr;
	lengths = 0;
}

template<class T>
inline Linklist<T>::~Linklist()
{
	Node<T> * temp = new Node<T>;
	while (front)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	front = rear = 0;
}

template<class T>
inline Linklist<T>::Linklist(const Linklist & L)
{
	if (&L == this)
		return false;
	if(!isEmpty())
	Clear_List();
	Node <T> *temp1 = L.front;
	for (int i = 0; i < L.lengths; i++,temp1=temp1->next)
	{
		Node <T> * temp2 = new Node <T>;
		temp2->item = temp1->item;
		temp2->next = NULL;
		Insert(temp2);
	}
	return *this;
}

template<class T>
inline Linklist<T> & Linklist<T>::operator=(const Linklist<T> & L)
{
	if (&L == this)
		return false;
	if (!isEmpty())
		Clear_List();
	Node <T> *temp1 = L.front;
	for (int i = 0; i < L.lengths; i++, temp1 = temp1->next)
	{
		Node <T> * temp2 = new Node <T>;
		temp2->item = temp1->item;
		temp2->next = NULL;
		Insert(temp2);
	}
	return *this;
}

template<class T>
inline bool Linklist<T>::Insert(int k, T & item)
{
	if (isFull())
	{
		cout << "The Linklist is full!\n";
		return false;
	}
	Node <T> *temp = new Node<T>;
	temp->item = item;
	temp->next = NULL;
	if (k == 1)
	{
		temp->next = front;
		front = temp;
	}
	else
	{
		Node<T> * add = front;
		for (int i = 1; i < k&&add; i++)
		add = add->next;
		temp->next = add->next;
		add->next = temp;
	}
	lengths++;
	return true;
}

template<class T>
inline bool Linklist<T>::Delete(int k,T & item)
{
	if (isEmpty())
	{
		cout << "The Linklist  is empty!\n";
		return false;
	}
	Node<T>* temp = front;
	Node <T> *L_temp = front;
	if (k == 1)
		front = front->next;
	else
	{
		for (int i = 1; i < k - 1 && L_temp; i++)
			L_temp = L_temp->next; //目标节点的前一个结点

		temp = L_temp->next; //目标节点

		L_temp->next = temp->next;
	}
	item = temp->item;
	delete temp;
	lengths--;
	return true;
}

template<class T>
inline void Linklist<T>::Clear_List()
{
	Node <T> * temp;
	//利用头结点指针来移动
	while (front)
	{
		temp = front->next;
		delete front;
		front = temp;
	}
}

template<class T>
inline bool Linklist<T>::Insert(T & item)
{
	Node<T>* temp = new Node<T>;
	temp->item = item;
	temp->next = NULL;
	if (isEmpty())
	{
		front = rear = temp;	
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
	lengths++;
	return true;
}

template<class T>
inline bool Linklist<T>::Find_poi(int k, T & x) const
{
	if (isEmpty() || k > lengths)
	{
		cout << "Error input!\n";
		return false;
	}

	Node<T> *temp = front;
	int i = 1;
	while (i < k&&temp)
	{
		temp = temp->next;
		i++;
	}
	if (temp)
	{
		x = temp->item;
		return true;
	}
	else
		return false;
}

template<class T>
inline bool Linklist<T>::Find_item(const T & x) const
{
	Node <T> *temp = front;
	int index = 1;
	while (temp&&temp->item != x)
	{
		temp = temp->next;
		index++;
	}
	if (temp)return index;
	return 0;
}

template<class T>
inline void Linklist<T>::ShowList() const
{
	Node<T> * temp = new Node<T>;
	temp = front;
	for (int i = 0; i < lengths; i++,temp=temp->next)
	{
		cout << temp->item << ' ';
	}
	cout << endl;
}