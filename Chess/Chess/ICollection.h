#ifndef ICollection_h
#define ICollection_h
#include "Element.h"

template<class T>
class ICollection
{
public:
	Element<T>* first;
	Element<T>* next;
	Element<T>* last;

	ICollection<T>()
	{
		this->first = nullptr;
		this->last = nullptr;
		this->next = nullptr;
	}

	virtual void add(T date) = 0;
	virtual T operator [](int index) = 0;

	virtual T get(int index) = 0;

	virtual int length() = 0;
};

#endif