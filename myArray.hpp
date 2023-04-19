#pragma once
#include <iostream>
using namespace std;
#include <string>

template <typename T>
class myArray
{
public:
	myArray& operator=(const myArray& array)
	{
		if (this->array != NULL)
		{
			delete[] this->array;
			this->array = NULL;
			this->size = 0;
			this->capacity = 0;
		}
		
		this->capacity = array.capacity;
		this->size = array.size;
		this->array = new T[array.capacity];

		for (int i = 0; i < this->size; i++)
		{
			this->array[i] = array.array[i];
		}
		return *this;
	}
	myArray(){}
	myArray(int size);
	myArray(const myArray& array);
	void show();//获取当前数组元素个数和数组容量
	~myArray();
private:
	int size;//元素个数
	int capacity;//数组容量
	T* array;//数组
};

template <typename T>
myArray<T>::myArray(int size)
{
	this->capacity = size;
	this->size = 0;
	this->array = new T[size];
}

template <typename T>
myArray<T>::~myArray()
{
	if (this->array != NULL)
	{
		delete[] this->array;
		this->array = NULL;
	}
} 

template <typename T>
myArray<T>::myArray(const myArray& array)
{
	this->size = array.size;
	this->capacity = array.capacity;
	this->array = new T[capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->array[i] = array.array[i];
	}
	return *this;
}

template<typename T>
void myArray<T>::show()
{
	cout << "size: " << this->size << "\t" << "capacity: " << this->capacity << endl;
}