#pragma once
#include<iostream>
#include<malloc.h>
#include<string>
using namespace std;
const int List_init_size = 100;
const int List_increment = 10;

template <typename T>
void Show_item(T item)
{
	cout << item << ' ';
}
//公式化描述的顺序表类定义
template <typename T>
class Linelist
{
private:
	T * elem;// 顺序表地址头
	int lengths;  //现有数据数
	int listsize;  //顺序表长度
	int Partition(int low, int high);
	void Q_Sort(int low, int high);
public:
	Linelist(int Size= List_init_size);
	~Linelist()
	{
		free(elem);
	}
	bool isFull()const { return lengths == 0; }
	bool isEmpty()const { lengths == listsize; }
	bool Insert(int i, T e);
	bool Delete_poi(int i,T & item);
	bool Delete_item(T e);
	void Show_list(void(*Visit)(T item))const;
	int Length()const { return lengths; }
	int locate_item(T & item);
	friend ostream & operator<< (ostream & os, const Linelist& L);
	void Quicksort();
};

template<typename T>
Linelist<T>::Linelist(int Size) :lengths(0), listsize(Size)
{
	elem = (T *)malloc(List_init_size * sizeof(T));
	if (!elem)
	{
		cout << "Memory allocation failed!\n";
		exit(1);
	}
}

template<typename T>
bool Linelist<T>::Insert(int i, T e)
{
	T  *p, *q;
	if (i<1 || i>lengths + 1)
	{
		cout << "Erroe positon input\n";
		return false;
	}
	//if memory not enough
	if (lengths > List_init_size)
	{
		T *newbase = (T*)realloc(elem, (List_init_size + List_increment) * sizeof(T));
		if (!newbase)
		{
			cout << "Memory allocation failed!\n";
			exit(1);
		}
		elem = newbase;
		listsize += List_increment;
	}
	q = &elem[i - 1]; //定位到插入位置
	for (p = &(elem[lengths - 1]); p >= q; p--)
	{
		//后移
		*(p + 1) = *p;
	}
	//插入
	*q = e;
	//更新大小
	++lengths;
	return true;
}

template<typename T>
bool Linelist<T>::Delete_poi(int i,T & item)
{
	if (i<1 || i>lengths + 1)
	{
		cout << "Erroe positon input\n";
		return false;
	}
	T *p, *q;
	p = &elem[i - 1];  //定位到删除位置
	item = *p;
	q = &(elem[lengths - 1]);
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--lengths;
	return true;
}

template<typename T>
bool Linelist<T>::Delete_item(T e)
{
	T *p, *q;
	int i = 0;
	p = q = elem;
	for (; p < elem + lengths - 1; p++)
	{
		if (*p == e)
		{
			i = p - q + 1;//定位
			Delete_poi(i);
			p = elem;
		}
	}
	if (i == 0)cout << "No found!\n";
	return true;
}

template<typename T>
void Linelist<T>::Show_list(void(*Visit)(T item)) const
{
	T * p = elem;
	int i = 0;
	while (i++ < lengths)
		Visit(*(p++));
	cout << endl;
}

template<typename T>
void Linelist<T>::Quicksort()
{
	Q_Sort(1, lengths - 1);
}

template<typename T>
int Linelist<T>::Partition(int low, int high)
{
	if (low<1 || high>lengths - 1)
	{
		cout << "Error input!\n";
		exit(1);
	}
	T pivotkry = elem[low];
	while (low < high)
	{
		while (low < high&&elem[high] >= pivotkry)--high;
		elem[low] = elem[high];
		while (low < high&&elem[low <= pivotkry])++low;
		elem[high] = elem[low];
	}
	elem[low] = elem[0];
	return low;
}

template<typename T>
void Linelist<T>::Q_Sort(int low, int high)
{
	int pivorkey;
	if (low < high)
	{
		pivorkey = Partition(low, high);
		Q_Sort(low, pivorkey - 1);
		Q_Sort(pivorkey + 1, high);
	}
}

template<typename T>
ostream & operator<<(ostream & os, const Linelist<T> & L)
{
	// TODO: 在此处插入 return 语句
	T * p = L.elem;
	while (p++)
		cout << *p << ' ';
	cout << endl;
	return os;
}

